
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND_SIZE 5
#define THRESHOLD 4

#define DEBUG 0


void splash_screen(const char* titles[], size_t lines) {
    printf("%s", "******************************************************************************\n");
    for(int i = 0; i < lines; ++i) {
        printf("%s", "*");
        int spaces = (80-strlen(titles[i]))/2 - 1;

        for(int j = 0; j < spaces-1; ++j) {
            printf("%s", " ");
        }
        printf("%s", titles[i]);
        for(int j = 0; j < spaces-1; ++j) {
            printf("%s", " ");
        }
        if(strlen(titles[i])%2!=0)
            printf(" ");
        printf("%s", "*\n");
    }
    printf("%s", "******************************************************************************\n");
}

void legacy_shuffle(int deck[][FACES]);
//void quick_shuffle(int deck[][FACES]);
void shuffle(int deck[][FACES], void (*algorithm) (int deck[][FACES]));
void deal(int deck[][FACES], const char* face[], const char* suit[]);
void print_card( const char* suit[],const char* face[], size_t i_suit, size_t y_face, int hide) {
    if(hide)
        printf("%s di %s\n", "*******", "*******");
    else
        printf("%s di %s\n", face[y_face], suit[i_suit]);
}
void find_card(int deck[][FACES], size_t card, size_t* row, size_t* column);
void hand_deal(int deck[][FACES], size_t* top_index, int hand[][2], size_t cards);
void AI_game(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]);
int eval_hand(int hand[HAND_SIZE][2]);
void print_array(int array[], size_t size){
    printf("%s", "\n[ ");
    for (int i = 0; i < size; ++i)
        printf("%d ", array[i]);
    printf("%s", "]\n");
}
void print_hand(int hand[HAND_SIZE][2],const char* suit[],const char* face[], const char* name, int hide){
#if DEBUG==1
    hide = 0;
#endif
    printf("---------------- %s -----------------\n", name);
    for(int i = 0; i < HAND_SIZE; ++i) {
        printf("%d)",i+1);
        print_card(suit, face, hand[i][0], hand[i][1], hide);
    }
    printf("-------------------------------------\n");
}



int main() {
    const char* titles[] = {"Welcome to Card Game", "made by Enrico Coppolecchia"};
    splash_screen(titles, 2);

    printf("insert your name: ");
    char *name;
    int bufsize = 150;
    name = (char *)malloc(bufsize * sizeof(char));
    if(name == NULL) {
        perror("Unable to allocate buffer\n");
        exit(1);
    }
    fgets(name, bufsize, stdin);
    int len = strlen(name);
    if(name[len-1] == '\n') name[len-1] = 0;
    //scanf("%20s", name);

    // inizializzo tutti gli elementi dell'array bidimensionale a 0
    int deck[SUITS][FACES] = {0};

    //mischio il mazzo tramite numeri random usando il timer di sistema
    srand(time(NULL));
    shuffle(deck,legacy_shuffle);

    // inizializzo l'array con i semi
    const char* suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Spade"};

    // inizializzo l'array con le facce
    const char* face[FACES] = {"Asso", "Due", "Tre", "Quattro", "Cinque",
                               "Sei", "Sette", "Otto", "Nove", "Dieci",
                               "Jack", "Regina", "Re"};

    int AI[HAND_SIZE][2] = {0};
    int player2[HAND_SIZE][2] = {0};

    size_t top_index = 0;
    hand_deal(deck, &top_index, AI, HAND_SIZE);
    hand_deal(deck, &top_index, player2, HAND_SIZE);

    print_hand(AI, suit, face, "AI",1);
    print_hand(player2, suit, face, name,0);

    AI_game(deck, &top_index, AI);

    int eval1 = eval_hand(AI);

    int eval2 = eval_hand(player2);
    printf("Hand value is %i\n", eval1);
    printf("Hand value is %i\n", eval2);
    if(eval1 > eval2)
        printf("AI wins!!");
    else if(eval2 > eval1)
        printf("Player 2 wins!!");
    else
        printf("No one is the winner!");

    return 0;
}


/////////////////////// FUNCTIONS //////////////////////////////////////////////////////

int count_couples(int hand[HAND_SIZE][2]) {
    int value = 0;
    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    for (int i = 0; i< FACES; ++i)
        if(freq[i]==2)
            value++;
    return value;
}

int count_triplet(int hand[HAND_SIZE][2]) {
    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    for (int i = 0; i< FACES; ++i)
        if(freq[i]==3)
            return 3;
    return 0;
}

int count_quartet(int hand[HAND_SIZE][2]) {
    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    for (int i = 0; i< FACES; ++i)
        if(freq[i]==4)
            return 4;
    return 0;
}

int same_color(int hand[HAND_SIZE][2]) {
    int freq[SUITS] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][0]]++;
#if DEBUG==1
    printf("COLOR");
    print_array(freq,SUITS);
#endif
    for (int i = 0; i< SUITS; ++i)
        if(freq[i]==HAND_SIZE)
            return 5;
    return 0;
}

// [0 0 1 1 1 1 1 0 0 0 0 0]
int is_scale(int hand[HAND_SIZE][2]) {
    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
#if DEBUG==1
    printf("FACES");
    print_array(freq,FACES);
#endif

    for (int i = 0; i< FACES; ++i) {
        if(freq[i]>1)
            return 0;
        if(freq[i]==0)
            continue;
        if(freq[i]==1) {
            int count = 0;
            for(int j = i; j < FACES; ++j) {
                if(freq[j]==1)
                    count++;
                if(freq[j]==2 || freq[j]==0)
                    break;
            }
            if (count==HAND_SIZE)
                return 6;
        }
    }
    return 0;
}



int eval_hand(int hand[HAND_SIZE][2]){

    if(is_scale(hand) > 0) return 6;
    if(same_color(hand) > 0) return 5;
    if(count_quartet(hand) > 0) return 4;
    if(count_triplet(hand) > 0) return 3;

    return count_couples(hand);
}

void legacy_shuffle(int deck[][FACES]) {
    for(size_t card = 0; card < CARDS; ++card) {
        size_t row = 0;
        size_t column = 0;

        // fintanto che non trovo una posizione libera genero casualmente posizioni
        // inefficiente e "potenzialmente" infinito
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while(deck[row][column] != 0);

        deck[row][column] = card;
    }
}

/* Questa funzione ha il solo scopo di essere esplicativa non ha una particolare esigienza.
passa un puntatore a funzione per rendere dinamica la scelta del tipo di algoritmo a runtime */
void shuffle(int deck[][FACES], void (*algorithm) (int deck[][FACES])) {

    algorithm(deck);
}


void hand_deal(int deck[][FACES], size_t* top_index, int hand[][2], size_t cards) {
#if DEBUG == 1
    printf("%s","---------------------------------------------------------------\n");
    printf("%s", "START deal for hand...\n");
#endif


    size_t i_suit = -1;
    size_t y_face = -1;
    for (size_t card = 0; card < cards; ++card) {

#if DEBUG == 1
        printf("\tdeal for %zu card...\n", card+1);
#endif
        i_suit = -1;
        y_face = -1;
        // trovo indirizzo carte
        find_card(deck, *top_index,  &i_suit, &y_face);

        if (i_suit != -1 && y_face != -1) {
#if DEBUG == 1
        printf("\t\tcard %zu found at deck(%zu, %zu) ...\n", *top_index, i_suit, y_face);
#endif
            hand[card][0] = i_suit;
            hand[card][1] = y_face;
            (*top_index) = (*top_index) + 1;
        }else {
#if DEBUG == 1
            printf("\t\tcard %zu not found \n", card);
#endif
            printf("FATAL! deck not completely shuffled!");
            break;
        }

    }
#if DEBUG == 1
    printf("%s", "END deal for hand.\n");
    printf("%s","---------------------------------------------------------------\n");
#endif
}

void deal(int deck[][FACES], const char* suit[], const char* face[]) {
    // definizione della funzione all'interno di una funzione per il principio del privilegio minimo
    //void find_card(int deck[][FACES], size_t card, size_t* row, size_t* column);

    // ciclo per tutte le carte
    size_t i_suit = -1;
    size_t y_face = -1;
    for (size_t card = 0; card < CARDS; ++card) {
        i_suit = -1;
        y_face = -1;
        // trovo indirizzo carte
        find_card(deck, card,  &i_suit, &y_face);
        if (i_suit != -1 && y_face != -1) {
            print_card(face, suit, i_suit, y_face,0);
        }
    }
}

void find_card(int deck[][FACES], size_t card, size_t* row, size_t* column) {
    for (size_t i = 0; i < SUITS; ++i) {
        for (size_t j = 0; j < FACES; ++j) {
            if (card == deck[i][j]) {
                *row = i;
                *column = j;
                return;
            }
        }
    }
}

void handle_couple(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]) {

    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    int toChange = 0;
    for (int i = 0; i < HAND_SIZE; ++i) {
        if(freq[hand[i][1]] < 2 && freq[hand[i][1]] > 0) {
            hand[i][1] = -1;
            toChange++;
        }
    }
    int deal[toChange][2];
    hand_deal(deck, top_index,deal, toChange);

    for(int i = 0; i < HAND_SIZE; ++i) {
        if(hand[i][1] == -1) {
            hand[i][0] = deal[toChange-1][0];
            hand[i][1] = deal[toChange-1][1];
            toChange--;
            if(toChange == 0)
                break;
        }
    }
    //int deal[toChange][2] = {};
}

void handle_triplet(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]) {

    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    int toChange = 0;
    for (int i = 0; i < HAND_SIZE; ++i) {
        if(freq[hand[i][1]] < 3 && freq[hand[i][1]] > 0) {
            hand[i][1] = -1;
            toChange++;
        }
    }
    int deal[toChange][2];
    hand_deal(deck, top_index,deal, toChange);

    for(int i = 0; i < HAND_SIZE; ++i) {
        if(hand[i][1] == -1) {
            hand[i][0] = deal[toChange-1][0];
            hand[i][1] = deal[toChange-1][1];
            toChange--;
            if(toChange == 0)
                break;
        }
    }
    //int deal[toChange][2] = {};
}

void handle_quartet(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]) {

    int freq[FACES] = {0};
    for (int i = 0; i < HAND_SIZE; ++i)
        freq[hand[i][1]]++;
    int toChange = 0;
    for (int i = 0; i < HAND_SIZE; ++i) {
        if(freq[hand[i][1]] < 4 && freq[hand[i][1]] > 0) {
            hand[i][1] = -1;
            toChange++;
        }
    }
    int deal[toChange][2];
    hand_deal(deck, top_index,deal, toChange);

    for(int i = 0; i < HAND_SIZE; ++i) {
        if(hand[i][1] == -1) {
            hand[i][0] = deal[toChange-1][0];
            hand[i][1] = deal[toChange-1][1];
            toChange--;
            if(toChange == 0)
                break;
        }
    }
    //int deal[toChange][2] = {};
}


void AI_game(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]) {
    int value = eval_hand(hand);
#if DEBUG == 1
    printf("AI: Found value = %d.\n", value);
#endif

    if(value > THRESHOLD)
        return;
    switch (value) {
        case 0:
            printf("AI: %s", "Change all cards..\n");
            hand_deal(deck, top_index, hand, HAND_SIZE);
            break;
        case 1:
            printf("AI: %s", "Change all cards but not the couple.\n");
            handle_couple(deck, top_index, hand);
            break;
        case 2:
            printf("AI: %s", "Change all cards but not the couples.\n");
            handle_couple(deck, top_index, hand);
            break;
        case 3:
            printf("AI: %s", "Change all cards but not the triplet.\n");
            handle_triplet(deck, top_index, hand);
            break;
        case 4:
            printf("AI: %s", "Change all cards but not the quartet.\n");
            handle_quartet(deck, top_index, hand);
            break;
        default:
            printf("AI: %s","The value is good");
    }
}
