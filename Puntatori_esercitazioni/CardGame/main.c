#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle(int deck[][FACES]);
void deal(int deck[][FACES], const char* face[], const char* suit[]);

int main() {
    // inizializzo tutti gli elementi dell'array bidimensionale a 0
    int deck[SUITS][FACES] = {0};
    //mischio il mazzo tramite numeri random usando il timer di sistema
    srand(time(NULL));
    shuffle(deck);

    // inizializzo l'array con i semi
    const char* suit[SUITS] = {"Cuori", "Quadri", "Fiori", "Spade"};
    // inizializzo l'array con le facce
    const char* face[FACES] = {"Asso", "Due", "Tre", "Quattro", "Cinque",
                               "Sei", "Sette", "Otto", "Nove", "Dieci",
                               "Jack", "Regina", "Re"};
    deal(deck, face, suit);
    return 0;
}

void shuffle(int deck[][FACES]) {

    for(size_t card = 1; card <= CARDS; ++card) {

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
void deal(int deck[][FACES], const char* face[], const char* suit[]) {
    void find_card(int deck[][FACES], size_t card, size_t* row, size_t* column);
    // ciclo per tutte le carte
    size_t i_face = -1;
    size_t y_suit = -1;
    for (size_t card = 1; card <= CARDS; ++card) {
        i_face = -1;
        y_suit = -1;
        // trovo indirizzo carte
        find_card(deck, card,  &y_suit, &i_face);
        if (i_face != -1 && y_suit != -1) {
            printf("%s di %s\n", face[i_face], suit[y_suit]);
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
