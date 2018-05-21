#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

class Paragraphx
{
    public:
    string sytuacja[100];
    string tresc[100];
    string odpA[100];
    string odpB[100];
    string odpC[100];
    string odpD[100];
	string idA[100];
	string idB[100];
	string idC[100];
	string idD[100];
	string wybor="0";

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

    while(getline(plik,linia))
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
	int X=0;

    while(true)
    {
            system("CLS");
            if(wybor==odpA[X]){wybor=idA[X];}
            if(wybor==odpB[X]){wybor=idB[X];}
            if(wybor==odpC[X]){wybor=idC[X];}
            if(wybor==odpD[X]){wybor=idD[X];}
            istringstream iss(wybor);
            iss>> X;
            if(wybor==sytuacja[X])
            {
                int k=0;
                while(true)
                {
                    Sleep(20);
                cout<<tresc[X].at(k);
                    k++;
                    if(tresc[X].at(k)=='$') { Sleep(200); cout<<endl<<endl; break; }
                }
                cout<<odpA[X]<<endl;
                cout<<odpB[X]<<endl;
                cout<<odpC[X]<<endl;
                cout<<odpD[X]<<endl<<endl;
                cout<<"Wybor interakcji : ";
                cin>>wybor;

            }
            else
            {
                cout<<"GAME OVER";
                break;
            }
    }
}

};

int main()
{
  Paragraphx Gra;
  Gra.wczytywanie();
  Gra.logika();
}

