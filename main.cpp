#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

class Paragraphx
{
    public:
    int dlugosc = 8;
    string * sytuacja = new string[dlugosc];
    string * tresc = new string[dlugosc];
    string * odpA = new string[dlugosc];
    string * odpB = new string[dlugosc];
    string * odpC = new string[dlugosc];
    string * odpD = new string[dlugosc];
	string * idA = new string[dlugosc];
	string * idB = new string[dlugosc];
	string * idC = new string[dlugosc];
	string * idD = new string[dlugosc];
	string wybor="1";

void wczytywanie()
{
    int nr_linii=1;
    int pytanie=0;
    string linia;

    fstream plik;
    plik.open("data.txt",ios::in);

    if (plik.good()==false)
    {
        cout<<"Nie udalo sie otworzyc pliku!";
        exit(0);
    }

    while(getline(plik,linia)) // WCZYTUJEMY Z PLIKU TEKSTOWEGO TEKST DO TABLIC JEDNOWYMIAROWYCH
    {
        switch(nr_linii)
        {
        	case 1: sytuacja[pytanie]=linia; 	   break;
            case 2: tresc[pytanie] = linia;        break;
            case 3: idA[pytanie] = linia;          break;
            case 4: odpA[pytanie] = linia;         break;
            case 5: idB[pytanie] = linia;          break;
            case 6: odpB[pytanie] = linia;         break;
            case 7: idC[pytanie] = linia;          break;
            case 8: odpC[pytanie] = linia;         break;
            case 9: idD[pytanie] = linia;          break;
            case 10: odpD[pytanie] = linia;        break;
            case 11:                               break;
        }

        if (nr_linii==11) {nr_linii=0;pytanie++;}
        nr_linii++;
    }
    plik.close();
	}

void logika()
{
	int X=1;
	string zle;

    while(true)
    {
            system("CLS");
            if(wybor==odpA[X]){wybor=idA[X];} // SPRAWDZAMY CZY KOMENDA ZOSTA£A WPISANA POPRAWNIE
            else if(wybor==odpB[X]){wybor=idB[X];} // JESLI TAK TO PRZYPISUJEMY JEJ WARTOS INDEKU ODPOWIEDZI
            else if(wybor==odpC[X]){wybor=idC[X];}
            else if(wybor==odpD[X]){wybor=idD[X];}
            else
            {
                ostringstream ss;   // ZAMIENIAMY TUTAJ INTA NA STRINGA, JESLI ZAMIENIMY NASZA WARTOSC X NA STRINGA I PRZYPISZEMY GO WYBOROWI
                ss << X;            // DZIEKI TEMU NACISNIECIE ZLYCH KOMEND SPOWODUJE POZOSTANIE W BIEZACYM POKOJU (SYTUACJI)
                zle = ss.str();
                wybor = zle;
            }
            istringstream iss(wybor); // KONWERSJA NASZEGO ID ZE STRING DO INT
            iss>> X;
            if(wybor==sytuacja[X]) // SPRAWDZAMY CZY NASZE ID ODPOWIEDZI JEST ZGODNE Z ID TRESCI FABULY
            {
                int k=0;
                while(true) // EFEKT WYPISYWANIA TRESCI NA EKRANIE
                {
                    Sleep(20);
                cout<<tresc[X].at(k);
                    k++;
                    if(tresc[X].at(k)=='$') { Sleep(200); cout<<endl<<endl; break; }
                }

            }
                if(X==0){Sleep(600); exit(0);} // SPRWDZAMY CZY ZGINELISMY
                cout<<odpA[X]<<endl;
                cout<<odpB[X]<<endl;
                cout<<odpC[X]<<endl;
                cout<<odpD[X]<<endl<<endl;
                cout<<"Wybor interakcji : ";
                cin>>wybor;

            }

    }

};

int main()
{
  Paragraphx Gra; // TWORZENIE OBJEKTU GRA
  Gra.wczytywanie(); // WYWO£YWANIE FUNKCJI Z KLASY Paragraphx
  Gra.logika();
}

