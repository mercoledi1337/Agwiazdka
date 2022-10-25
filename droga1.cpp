// droga1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iomanip> 

float min(float F[20][20], int O[20][20]) {
    float tmp = INT_MAX;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (O[i][j] == 1) {
                if (F[i][j] < tmp) {
                    if (F[i][j] != 0) {
                        tmp = F[i][j];
                    }

                }
            }
        }
    }
    return tmp;
}

int minX(float t[20][20], int O[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (t[i][j] == min(t,O)) {
                return i;
            };
        }
    }

}

int minY(float t[20][20], int O[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (t[i][j] == min(t,O)) {
                return j;
            };
        }
    }
}

void zerowanie(int t[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            t[i][j] = 0;
        }
    }
}


void zerowanie1(float t[20][20]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            t[i][j] = 0;
        }
    }
}

bool czyJestDojscie(int O[20][20])
{
    int zawiera = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0;j < 20; j++) {
            if (O[i][j] == 1) zawiera++;
        }
    }
    if (zawiera == 0) return false;
    else
    {
        return true;
    }
}

int ileDoStartu(int x, int y, int x1, int y1, int R[20][20]) {
    int tmpX = x;
    int tmpY = y;
    int licznik = 1;
    while (tmpX != x1 || tmpY != y1) {
        if (R[tmpX][tmpY] == 4) {
            licznik++;
            tmpY++;
        }
        else if (R[tmpX][tmpY] == 2) {
            licznik++;
            tmpY--;
        }
        else if (R[tmpX][tmpY] == 3) {
            licznik++;
            tmpX--;
        }
        else if (R[tmpX][tmpY] == 1) {
            licznik++;
            tmpX++;
        }
    }
    return licznik;
}

void polaObok(int O[20][20], int Z[20][20],int R[20][20],float F[20][20],int tablica[20][20],float F1[20][20], int celX, int celY, int startX,int startY) {

    int tmpX = minX(F, O);
    int tmpY = minY(F, O);
        
        if ((tmpY - 1) >= 0 && tablica[tmpX][tmpY - 1] != 5) { 
            int g = ileDoStartu(tmpX, tmpY, startX, startY, R);
            float tmp = g + sqrt(((tmpX - celX) * (tmpX - celX)) + (((tmpY - 1) - celY) * ((tmpY - 1) - celY))); // f
             if (Z[tmpX][tmpY - 1] != 3) { // sprawdzamy czy nie jest w zamkniętej
                 if (F1[tmpX][tmpY - 1] != 0 && F1[tmpX][tmpY - 1] > tmp) {                  
                          // tu też wage
                         R[tmpX][tmpY - 1] = 4;
                 }
                 else if (F1[tmpX][tmpY - 1] == 0) {
                     O[tmpX][tmpY - 1] = 1; // dodajemy do otwartej
                     F[tmpX][tmpY - 1] = tmp; // a tu wage
                     F1[tmpX][tmpY - 1] = tmp; // tu też wage
                     R[tmpX][tmpY - 1] = 4;
                 }               
             }         
        }

        if ((tmpX - 1) >= 0 && tablica[tmpX - 1][tmpY] != 5) { // pole lewe    
            int g = ileDoStartu(tmpX, tmpY, startX, startY, R);
            float tmp = g + sqrt(((tmpX - 1) - celX) * ((tmpX - 1) - celX) + ((tmpY - celY) * (tmpY - celY)));
             if (Z[tmpX - 1][tmpY] != 3) {
                 if (F1[tmpX - 1][tmpY] != 0 && F1[tmpX - 1][tmpY] > tmp) {                  
                          // tu też wage
                         R[tmpX - 1][tmpY] = 1;
                 }
                 else if (F1[tmpX - 1][tmpY] == 0) {
                     O[tmpX - 1][tmpY] = 1; // dodajemy do otwartej
                     F[tmpX - 1][tmpY] = tmp; // a tu wage
                     F1[tmpX - 1][tmpY] = tmp; // tu też wage
                     R[tmpX - 1][tmpY] = 1;
                 }
                }
            
            

        }
        if ((tmpY + 1) < 20 && tablica[tmpX][tmpY + 1] != 5) { // pole górne
            int g = ileDoStartu(tmpX, tmpY, startX, startY, R);
            float tmp = g + sqrt(((tmpX - celX) * (tmpX - celX)) + (((tmpY + 1) - celY) * ((tmpY + 1) - celY)));
            if (Z[tmpX][tmpY + 1] != 3) {
                if (F1[tmpX][tmpY + 1] != 0 && F1[tmpX][tmpY + 1] > tmp) {
                         // tu też wage
                        R[tmpX][tmpY + 1] = 2; 
                }
                else if (F1[tmpX][tmpY + 1] == 0) {
                    O[tmpX][tmpY + 1] = 1; // dodajemy do otwartej
                    F[tmpX][tmpY + 1] = tmp; // a tu wage
                    F1[tmpX][tmpY + 1] = tmp; // tu też wage
                    R[tmpX][tmpY + 1] = 2;
                }
            }
            
            
            

        }
        if ((tmpX + 1) < 20 && tablica[tmpX + 1][tmpY] != 5) { // pole prawe
            int g = ileDoStartu(tmpX, tmpY, startX, startY, R);
            float tmp =g + sqrt(((tmpX + 1) - celX) * ((tmpX + 1) - celX) + ((tmpY - celY) * (tmpY - celY)));
            if (Z[tmpX + 1][tmpY] != 3) {
                if (F1[tmpX + 1][tmpY] != 0 && F1[tmpX + 1][tmpY] > tmp) {
                        // tu też wage
                        R[tmpX + 1][tmpY] = 3; 
                }
                else if (F1[tmpX + 1][tmpY] == 0) {
                    O[tmpX + 1][tmpY] = 1; // dodajemy do otwartej
                    F[tmpX + 1][tmpY] = tmp; // a tu wage
                    F1[tmpX + 1][tmpY] = tmp; // tu też wage
                    R[tmpX + 1][tmpY] = 3;
                }
            }
             
            
        }
        

        O[tmpX][tmpY] = 0;
        Z[tmpX][tmpY] = 3;
        F[tmpX][tmpY] = 0;


    
}



void droga(int R[20][20], int tablica[20][20],float F1[20][20], int celX, int celY, int startX, int startY) {
    tablica[celX][celY] = 3;
    tablica[startX][startY] = 3;
    int tmpX = celX;
    int tmpY = celY;
    while (tmpX != startX || tmpY != startY) {
        if (R[tmpX][tmpY] == 4) {
            tablica[tmpX][tmpY + 1] = 3;
            tmpY++;
        }
        else if (R[tmpX][tmpY] == 2) {
            tablica[tmpX][tmpY - 1] = 3;
            tmpY--;
        }
        else if (R[tmpX][tmpY] == 3) {
            tablica[tmpX - 1][tmpY] = 3;
            tmpX--;
        }
        else if (R[tmpX][tmpY] == 1) {
            tablica[tmpX + 1][tmpY] = 3;
            tmpX++;
        }
    }   
}

int main()
{

    int tablica[20][20];
    std::ifstream file("grid.txt");
    std::vector<std::string> linia;
    if (file.is_open()) { // otwieramy plik
        std::string line;
        std::vector<int> liniaTmp; // tymczasowa linia do której zapisuje linie z mapy

        while (std::getline(file, line)) { // czytanie linia po lini pliku


            //  std::cout << line.c_str() << "\n";
            linia.push_back(line.c_str()); // wczucanie lini do vektora stringów

        }
        std::cout << "\n";
        int y = 0;
        int x = 0;
        for (int i = 0; i < linia.size(); i++) {
            std::string tmp = linia[i]; // tymczasowa linia ktorej będziemy używać do wyciągania charów
            //   std::cout << "\n";
            y = 0;
            for (int j = 0; j < tmp.size(); j++) {
                char a = tmp[j];
                if (a != ' ') {
                    int ia = a - '0';
                    tablica[x][y] = ia; // ostateczna tablica na której będziemy pracować
                    //   std::cout << tablica[x][y];
                    y++;

                }

            }

            x++;

        }


        file.close();
    }

    int O[20][20];
    int Z[20][20];
    int R[20][20];
    float F[20][20];
    float F1[20][20];

    zerowanie(O);
    zerowanie(Z);
    zerowanie(R);
    zerowanie1(F);
    zerowanie1(F1);

    int x;
    int y;
    int x1;
    int y1;
    std::cout << "podaj x startu oraz y startu \n" ;
    std::cin >> y >> x;
    std::cout << "podaj x celu oraz y celu \n";
    std::cin >> y1 >> x1;
    
    

    O[x][y] = 1;
    F[x][y] = 0.1;

    // std::cout << minX(F, O);
   //  std::cout << minY(F, O);
    while (O[x1][y1] != 1) {
        polaObok(O, Z, R, F, tablica,F1, x1, y1, x, y);
        if (czyJestDojscie(O) == false) break;
    }
    if (czyJestDojscie(O) == true) {
        droga(R, tablica, F1, x1, y1, x, y);
    }
    else std::cout << "nie ma dojscia";
        
    
   
    std::cout << "\n";
    std::cout << "\n";
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout << O[i][j];
        }
        std::cout << " ";
        for (int j = 0; j < 20; j++) {
            std::cout << R[i][j];
        }
        std::cout << " ";
        for (int j = 0; j < 20; j++) {
            std::cout << tablica[i][j] << " ";
        }
        
        std::cout << "\n";
    }
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
