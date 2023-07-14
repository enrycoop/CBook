#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND_SIZE 5

#define DEBUG 0

void legacy_shuffle(int deck[][FACES]);
//void quick_shuffle(int deck[][FACES]);
void shuffle(int deck[][FACES], void (*algorithm) (int deck[][FACES]));

void deal(int deck[][FACES], const char* face[], const char* suit[]);

void print_card( const char* suit[],const char* face[], size_t i_suit, size_t y_face) {
     printf("%s di %s\n", face[y_face], suit[i_suit]);
}
void find_card(int deck[][FACES], size_t card, size_t* row, size_t* column);


void hand_deal(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]);

int eval_hand(int hand[HAND_SIZE][2]);


int main() {
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
    //deal(deck, face, suit);
    int hand[HAND_SIZE][2] = {0};
    size_t top_index = 0;
    hand_deal(deck, &top_index, hand);

    for(int i = 0; i < HAND_SIZE; ++i) {
        print_card(suit, face, hand[i][0], hand[i][1]);
    }
    printf("%s","\n----------------------------------\n");
    printf("Hand value is %i", eval_hand(hand));


    return 0;
}

int count_couples(int hand[HAND_SIZE][2]) {
    int value = 0;
    for (int i = 0; i < HAND_SIZE-1; ++i) {
        for (int j = i+1;j < HAND_SIZE; ++j) {
            if (hand[i][1] == hand[j][1])
                value++;
        }
    }
    return value;
}
/*int count_triplet(int hand[HAND_SIZE][2]);
int count_quartet(int hand[HAND_SIZE][2]);
int same_color(int hand[HAND_SIZE][2]);
int scale(int hand[HAND_SIZE][2]);
*/
int eval_hand(int hand[HAND_SIZE][2]){
    int value = 0;
    value += count_couples(hand);
    /*value += count_triplet(hand);
    value += count_quartet(hand);
    value += same_color(hand);
    value += scale(hand);*/
    return value;
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


void hand_deal(int deck[][FACES], size_t* top_index, int hand[HAND_SIZE][2]) {
#if DEBUG == 1
    printf("%s", "START deal for hand...\n");
#endif


    size_t i_suit = -1;
    size_t y_face = -1;
    for (size_t card = 0; card < HAND_SIZE; ++card) {

#if DEBUG == 1
        printf("\tdeal for %zu card...\n", card+1);
#endif
        i_suit = -1;
        y_face = -1;
        // trovo indirizzo carte
        find_card(deck, *top_index,  &i_suit, &y_face);

        if (i_suit != -1 && y_face != -1) {
#if DEBUG == 1
        printf("\t\tcard %zu found at deck(%zu, %zu) ...\n", *top_index, y_suit, i_face);
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
            print_card(face, suit, i_suit, y_face);
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
