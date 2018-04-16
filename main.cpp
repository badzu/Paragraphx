//#include "baza.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <windows.h>
 
using namespace std;
 
string opis;
string tresc[4];
string odpA[4], odpB[4], odpC[4], odpD[4];
string odpowiedz;
int i=0;
 
 
 
 
int logika()
{
	switch(i)
	{
		case 0 :
			
		{
			if(odpowiedz==odpA[i]) i=0;
			if(odpowiedz==odpB[i]) i=2;
			if(odpowiedz==odpC[i]) i=999;
			if(odpowiedz==odpD[i]) i=1;
			break;
		}
		
		case 1 :
			
		{
			if(odpowiedz==odpA[i]) i=0;
			if(odpowiedz==odpB[i]) i=2;
			if(odpowiedz==odpC[i]) i=999;
			if(odpowiedz==odpD[i]) i=1;
			break;
		}
		
		case 2 :
			
		{
			if(odpowiedz==odpA[i]) i=1;
			if(odpowiedz==odpB[i]) i=3;
			if(odpowiedz==odpC[i]) i=3;
			if(odpowiedz==odpD[i]) i=3;
			break;
		}
		
		case 3 :
			
		{
			if(odpowiedz==odpA[i]) i=999;
			if(odpowiedz==odpB[i]) i=999;
			if(odpowiedz==odpC[i]) i=999;
			if(odpowiedz==odpD[i]) i=0;
			break;
		}	
	}
}



 
int main()
{
    int nr_linii=1;
    string linia;
    int nr_pytania=0;

 	
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
        	case 1: opis;  							 break;
            case 2: tresc[nr_pytania] = linia;       break;
            case 3: odpA[nr_pytania] = linia;        break;
            case 4: odpB[nr_pytania] = linia;        break;
            case 5: odpC[nr_pytania] = linia;        break;
            case 6: odpD[nr_pytania] = linia;        break;
        }
 
        if (nr_linii==6) {nr_linii=0; nr_pytania++;}
        nr_linii++;
    }
 
    plik.close();
 
    while(true)
    {
    	int x=0;
    	while(1)
    	{
    	Sleep(15);
    	cout<<tresc[i].at(x);
    	x++;
    	if(tresc[i].at(x)=='$') { Sleep(200); cout<<endl; break; }
		}
        cout<<"* "<<odpA[i]<<endl;
        cout<<"* "<<odpB[i]<<endl;
        cout<<"* "<<odpC[i]<<endl;
        cout<<"* "<<odpD[i]<<endl;
        cout<<"Twoja odpowiedz: ";			
        cin>>odpowiedz;
 
 		logika();
 		system("cls");
 		odpowiedz.clear();
 
	}
}


