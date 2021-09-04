#include <iostream>
#include <list>
using namespace std;

class hashKlasa
{
private:
    int bucket; //broj elemenata liste, velicina hash tablice
    list<int>* hashTablica; //stvaranje hash tablice

public:
    hashKlasa(int a) //konstruktor
    {
        bucket = a;
        hashTablica = new list<int>[bucket];
    }

    int hashFunkcija(int a) //jednostavna hash funkcija koja postavlja vrijednosti na odredjenu poziciju u hash tablici
    {
        return (a % bucket);
    }

    void unosElemenata(int key) //metoda za umetanje elemenata u hash tablicu
    {
        //dobivanje hash indexa za kljuc
        int indexkey = hashFunkcija(key);
        hashTablica[indexkey].push_back(key);
    }

    void prikazTablice() //metoda za prikaz tablice i svih vrijednosti
    {

        for (int i = 0; i < bucket; i++)
        {
            cout << i;
            list<int>::iterator j = hashTablica[i].begin();
            for (; j != hashTablica[i].end(); j++)
            {
                cout << "---->" << *j;
            }
            cout << endl;
        }
    }

    void traziElement(int element) //metoda koja trazi element u hash tablici
    {
        int a = 0; //ako je element nadjen zastavica "a" se postavlja na 1
        int vratiIndex;
        int indexKljuc = hashFunkcija(element);
        list<int>::iterator i = hashTablica[indexKljuc].begin();
        for (; i != hashTablica[indexKljuc].end(); i++)
        {
            if (*i == element)
            {
                a = 1;
                vratiIndex = indexKljuc;
                break;
            }
        }

        if (a == 1)
        {
            cout << "Trazeni element je pronadjen." << "\nIndex trazene vrijednosti je: " << vratiIndex << endl;
        }

        else
        {
            cout << "\nElement ne postoji" << endl;
        }
    }

    ~hashKlasa() //destruktor
    {
        delete[]hashTablica;
    }
};

int main()
{
    int velicinaTablice, odabir, element;

    cout << "Unesite velicinu hash tablice: ";
    cin >> velicinaTablice;
    hashKlasa hashElement(velicinaTablice);
    while (1)
    {
        cout << "\n1. Unos vrijednosti u tablicu" << endl;
        cout << "2. Trazi element u tablici" << endl;
        cout << "3. Prikaz tablice" << endl;
        cout << "4. Izlaz\n" << endl;
        cout << "Vas odabir: ";
        cin >> odabir;
        switch (odabir)
        {
        case 1:cout << "\nUnesi element ";
            cin >> element;
            hashElement.unosElemenata(element);
            break;

        case 2:cout << "\nUnesite element koji zelite naci: ";
            cin >> element;
            hashElement.traziElement(element);
            break;

        case 3:hashElement.prikazTablice();
            break;

        case 4:return 0;

        default:cout << "Pogresna vrijednost." << endl;
        }
    }
    return 0;
}