/*448417*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

/*Liczba wierszy planszy*/
#ifndef WIERSZE
 #define WIERSZE 10
 #endif

/* Liczba kolumn planszy*/
#ifndef KOLUMNY 
#define KOLUMNY 15
#endif

/*Liczba rodzajów klocków*/
#ifndef RODZAJE
#define RODZAJE 4
#endif

/*Oznaczenie pustego pola*/
#define PUSTE '.'

void wczytajPlansze(char plansza[WIERSZE][KOLUMNY]) {
    for (int w = 0; w < WIERSZE; w++ ) {
            for (int k = 0; k <= KOLUMNY; k++) {
                if (k == KOLUMNY) getchar();
                else plansza[w][k] = (char) getchar();
            }
    }
}

void drukujPlansze(char plansza[WIERSZE][KOLUMNY]) {
    for (int w = 0; w < WIERSZE; w++) {
        for (int k = 0; k < KOLUMNY; k++) {
            printf ("%c", plansza[w][k]);
            }
        printf("\n");
    }
}

/*Usuwa wszystkie klocki danej grupy*/
void usunKlocek(char plansza[WIERSZE][KOLUMNY],
                char rodzaj, int w, int k) {
    if (plansza[w][k] == rodzaj) {
        plansza[w][k] = PUSTE;
        if (w > 0) usunKlocek(plansza, rodzaj, w - 1, k);
        if (w < WIERSZE - 1) usunKlocek(plansza, rodzaj, w + 1, k);
        if (k > 0) usunKlocek(plansza, rodzaj, w , k - 1);
        if (k < KOLUMNY - 1) usunKlocek(plansza, rodzaj, w, k + 1);
    }
    else return;
}

/*Sprawdza czy wskazane przez uzytkownika pole jest elementem
grupy, jesli jest zwraca 1 wpp. zwraca 0*/
int sprawdzKlocek(char plansza[WIERSZE][KOLUMNY],
                  char rodzaj, int w, int k) {
    if (rodzaj != PUSTE) {
        if (w != 0) {
            if (plansza[w-1][k] == rodzaj) return 1;
        }
        if (w != WIERSZE - 1) {
            if (plansza[w+1][k] == rodzaj) return 1;
        }
        if (k != 0) {
            if (plansza[w][k - 1] == rodzaj) return 1;
        }
        if (k != KOLUMNY - 1) {
            if (plansza[w][k +1] == rodzaj) return 1;
        }
    }
    return 0;
}

/*Rozpoznaje rodzaj, jesli moze to usuwa dana grupe,
 wiersz, kolumna - wspolrzedne komorki wpisanej przez gracza*/
void usunGrupe(char plansza[WIERSZE][KOLUMNY], 
				int wiersz, int kolumna) {
    char rodzaj = plansza[wiersz][kolumna];
    if (sprawdzKlocek(plansza, rodzaj, wiersz, kolumna)) {
        usunKlocek(plansza, rodzaj, wiersz, kolumna);
    }
}

/*Przesuwa puste komorki w kolumnach na gore, komorki 
z wartosciami spadaja na dol*/
void porzadkujWiersze(char plansza[WIERSZE][KOLUMNY]) {
    for (int k = 0; k < KOLUMNY; k++) {
        for (int w = WIERSZE - 1; w >= 0; w--){
            if (plansza[w][k] == PUSTE){
                int wZamiana = w - 1;					
                int koniec = 0;
                while (wZamiana >= 0 && !koniec) {              //szukam niepustej komorki wyzej
                    if (plansza[wZamiana][k] != PUSTE) {		
                        plansza[w][k] = plansza[wZamiana][k];
                        plansza[wZamiana][k] = PUSTE;
                        koniec = 1;
                    }
                    else wZamiana--;
                }
            }
        }
    }

}

/*Przesuwa puste kolumny na prawo*/
void porzadkujKolumny(char plansza[WIERSZE][KOLUMNY]) {
    int kolumna = 0;
    int koniec = 0;
    while (kolumna < KOLUMNY && !koniec) {
        if (plansza[WIERSZE - 1][kolumna] == PUSTE) {
            int kZamiana = kolumna + 1;
            while ((kZamiana < KOLUMNY) &&
                (plansza[WIERSZE - 1][kZamiana] == PUSTE)) {
                    kZamiana++;
            }
            if (kZamiana == KOLUMNY) {
                koniec = 1;                                 //wszystkie kol. na prawo puste
            }
            else {
                for (int w = 0; w < WIERSZE; w++) {					
                    plansza[w][kolumna] = plansza[w][kZamiana];
                    plansza[w][kZamiana] = PUSTE;
                }
            }
        }
        kolumna++;
    }   
}

void porzadkujPlansze(char plansza[WIERSZE][KOLUMNY]) {
    porzadkujWiersze(plansza);
    porzadkujKolumny(plansza);
}

int main(int argc, char *argv[]) {
    assert(argc == 3);							/*zeby uzyc argc*/
    int wiersz = atoi(argv[1]);                 //wspolrz. kom. wskazanej przez gracza
    int kolumna = atoi(argv[2]);
    char plansza[WIERSZE][KOLUMNY];
    wczytajPlansze(plansza);
    usunGrupe(plansza, wiersz, kolumna);
    porzadkujPlansze(plansza);
    drukujPlansze(plansza);
    return 0;
}
