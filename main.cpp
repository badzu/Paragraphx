#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include<sstream>
using namespace std;

class ParaX
{
    public:
    string sytuacja[5];
    string tresc[5];
    string odpA[5];
    string odpB[5];
    string odpC[5];
    string odpD[5];
	string idA[5]; int idxA[5];
	string idB[5]; int idxB[5];
	string idC[5]; int idxC[5];
	string idD[5]; int idxD[5];

	string wybor="0";

    int wczytywanie()
{
    int nr_linii=1;
    int pytanie=0;
    string linia;
    int wartosc;

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
        	case 1: sytuacja[pytanie]=linia; 			   break;
            case 2: tresc[pytanie] = linia;         break;
            case 3: idA[pytanie] = linia;        break;
            case 4: odpA[pytanie] = linia;        break;
            case 5: idB[pytanie] = linia;        break;
            case 6: odpB[pytanie] = linia;        break;
            case 7: idC[pytanie] = linia;        break;
            case 8: odpC[pytanie] = linia;        break;
            case 9: idD[pytanie] = linia;        break;
            case 10: odpD[pytanie] = linia;        break;
            case 11: break;
        }

        if (nr_linii==11) {nr_linii=0;pytanie++;}
        nr_linii++;
    }

    plik.close();

	}

	int control()
	{

	int i, X=0;
    while(true)
    {
            if(wybor==odpA[X]){wybor=idA[X];}
            if(wybor==odpB[X]){wybor=idB[X];}
            if(wybor==odpC[X]){wybor=idC[X];}
            if(wybor==odpD[X]){wybor=idD[X];}
            istringstream iss(wybor);
            iss>> X;
            if(wybor==sytuacja[X])
                {

                    cout<<tresc[X]<<endl;
                    cout<<odpA[X]<<endl;
                    cout<<odpB[X]<<endl;
                    cout<<odpC[X]<<endl;
                    cout<<odpD[X]<<endl<<endl;
                    cin>>wybor;

                }
    }

}
};


int main()
{
  ParaX Tekst;
  Tekst.wczytywanie();
  Tekst.control();

}

