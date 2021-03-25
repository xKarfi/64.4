#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class plik 
{

public:
	
    ifstream pIn;
    plik();
    ~plik();

};

plik::plik() 
{
    pIn.open("dane_obrazki.txt");
}

plik::~plik() 
{
    pIn.close();
}

class obraz 
{
	
public:
	
    int ktoryObraz = 0;
    vector <string> obraz;
    void get(string numbers);
    void Sprawdz();
    void Wyczysc();
};

void obraz::get(string numbers) 
{
    obraz.push_back(numbers);
}


void obraz::Sprawdz() 
{
    int x, y, IleX = 0, IleY = 0, zlyX = 0, zlyY = 0;
    ktoryObraz++;
    for (int i = 0; i < obraz.size() - 1; i++) 
	{
        for (int j = 0; j < obraz.size() - 1; j++) 
		{

            if (obraz[i][j] == '1') 
			{
                IleX++;
            }
            if (obraz[j][i] == '1') 
			{
                IleY++;
            }

        }
        if ((IleX % 2 == 0 && obraz[i][20] == '1') || (IleX % 2 == 1 && obraz[i][20] == '0')) 
		{
            zlyX++;
            y = i;

        }

        if ((IleY % 2 == 0 && obraz[20][i] == '1') || (IleY % 2 == 1 && obraz[20][i] == '0'))
		{
            zlyY++;
            x = i;
        }
        IleX = 0;
        IleY = 0;
    }
    
    if ((zlyX == 1 && zlyY == 1)) 
	{
		cout<< ktoryObraz<<", " << y + 1 << ", " << x + 1 << endl;
    } 
	else if ((zlyX == 0 && zlyY == 1))
	{
        cout<< ktoryObraz<<", " << "21" << ", " << x + 1 << endl;
    } 
	else if ((zlyX == 1 && zlyY == 0)) 
	{
         cout<< ktoryObraz<<", " << y+1 << ", " << "21" << endl;
    }
    
    zlyX = 0;
    zlyY = 0;
    
}

void obraz::Wyczysc() 
{
    obraz.clear();
}

int main() 
{
    plik p;
    obraz o;
    string tem;
    while (!p.pIn.eof()) 
	{
        for (int i = 0; i < 21; i++) 
		{
            p.pIn >> tem;
            o.get(tem);
        }
        o.Sprawdz();
        o.Wyczysc();
    }
}
