#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

struct om
{
    char nume[50], prenume[50];
};

struct data
{
    char zi[3], luna[3], an[15];
};

struct masina
{
    char marca[20];
    char model[20];
    char NrInmatriculare[15];
    char culoare[20];
    data DataFabricare;
    om proprietar;
};

void adaugare(masina v[1000], int &n)
{
    masina Vehicul;
    cin.get();
    cout << "Introduceti marca: ";
    cin.getline(Vehicul.marca, 20);
    cout << "Introduceti modelul: ";
    cin.getline(Vehicul.model, 20);
    cout << "Introduceti numarul de inmatriculare: ";
    cin.getline(Vehicul.NrInmatriculare, 15);
    cout << "Introduceti culoarea: ";
    cin.getline(Vehicul.culoare, 20);
    cout << "Introduceti ziua, luna si anul fabricarii(format zz.ll.aaaa): ";
    cin.getline(Vehicul.DataFabricare.zi, 3, '.');
    cin.getline(Vehicul.DataFabricare.luna, 3, '.');
    cin.getline(Vehicul.DataFabricare.an, 15, '\n');
    cout << "Introduti nume proprietar: ";
    cin.getline(Vehicul.proprietar.nume, 50);
    cout << "Indroduceti prenume proprietar: ";
    cin.getline(Vehicul.proprietar.prenume, 50);
    v[n] = Vehicul;
    n++;
    fstream f("BazaDeDate.dat", ios::app);
    f << Vehicul.marca << " |" << Vehicul.model << " |" << Vehicul.NrInmatriculare << " |" << Vehicul.culoare << " |";
    f << Vehicul.DataFabricare.zi << "." << Vehicul.DataFabricare.luna << "." << Vehicul.DataFabricare.an << " |";
    f << Vehicul.proprietar.nume << " |" << Vehicul.proprietar.prenume << endl;
    f.close();
}

void inserare(masina v[1000], int& nr)
{
    int lungime;
    masina Vehicul;
    cin.get();
    cout << "Introduceti marca: ";
    cin.getline(Vehicul.marca, 20);
    lungime = strlen(Vehicul.marca);
    Vehicul.marca[lungime] = ' '; Vehicul.marca[lungime + 1] = '\0';
    cout << "Introduceti modelul: ";
    cin.getline(Vehicul.model, 20);
    lungime = strlen(Vehicul.model);
    Vehicul.model[lungime] = ' '; Vehicul.model[lungime + 1] = '\0';
    cout << "Introduceti numarul de inmatriculare: ";
    cin.getline(Vehicul.NrInmatriculare, 15);
    lungime = strlen(Vehicul.NrInmatriculare);
    Vehicul.NrInmatriculare[lungime] = ' '; Vehicul.NrInmatriculare[lungime + 1] = '\0';
    cout << "Introduceti culoarea: ";
    cin.getline(Vehicul.culoare, 20);
    lungime = strlen(Vehicul.culoare);
    Vehicul.culoare[lungime] = ' '; Vehicul.culoare[lungime + 1] = '\0';
    cout << "Introduceti ziua, luna si anul fabricarii(format zz.ll.aaaa): ";
    cin.getline(Vehicul.DataFabricare.zi, 3, '.');
    cin.getline(Vehicul.DataFabricare.luna, 3, '.');
    cin.getline(Vehicul.DataFabricare.an, 15, '\n');
    lungime = strlen(Vehicul.DataFabricare.an);
    Vehicul.DataFabricare.an[lungime] = ' '; Vehicul.DataFabricare.an[lungime + 1] = '\0';
    cout << "Introduti nume proprietar: ";
    cin.getline(Vehicul.proprietar.nume, 50);
    cout << "Indroduceti prenume proprietar: ";
    cin.getline(Vehicul.proprietar.prenume, 50);
    lungime = strlen(Vehicul.proprietar.nume);
    Vehicul.proprietar.nume[lungime] = ' '; Vehicul.proprietar.nume[lungime + 1] = '\0';

    int pozitieInserare;
    cout << "Pe ce pozitie vreti sa inserati masina(pozitiile pleaca de la 1)? ";
    cin >> pozitieInserare;
    pozitieInserare--;

    for(int i = nr; i > pozitieInserare; i--)
    {
        v[i] = v[i - 1];
    }
    v[pozitieInserare] = Vehicul;
    nr++;

    ofstream f("BazaDeDate.dat");
    for(int i = 0; i < nr; i++)
    {
        f << v[i].marca << "|" << v[i].model << "|" << v[i].NrInmatriculare << "|" << v[i].culoare << "|";
        f << v[i].DataFabricare.zi << "." << v[i].DataFabricare.luna << "." << v[i].DataFabricare.an << "|";
        f << v[i].proprietar.nume << "|" << v[i].proprietar.prenume << endl;
    }
    f.close();
}

void stergere(masina v[1000],int &n)
{
    char s[15];
    cout << "Introduceti numarul de inmatriculare al masinii pe care doriti sa o stergeti: ";
    cin.get();
    cin.getline(s, 15);
    int nr = strlen(s);
    s[nr] = ' '; s[nr + 1] = '\0';
    for(int i = 0; i < n; i++)
    {
        if(strcmp(s, v[i].NrInmatriculare) == 0)
        {
            for(int j = i; j < n - 1; j++)
            {
                v[j] = v[j + 1];
            }
            n--;
        }
    }
    fstream f("BazaDeDate.dat", ios::out);
    for(int i = 0; i < n; i++)
    {
        f << v[i].marca << "|" << v[i].model << "|" << v[i].NrInmatriculare << "|" << v[i].culoare << "|";
        f << v[i].DataFabricare.zi << "." << v[i].DataFabricare.luna << "." << v[i].DataFabricare.an << "|";
        f << v[i].proprietar.nume << "|" << v[i].proprietar.prenume << endl;
    }
    f.close();
}

int compara(masina v[], int ok, int i, int j, char x)
{
    int val;
    if(ok == 1)
    {
        val = strcmp(v[i].NrInmatriculare, v[j].NrInmatriculare);
    }
    else if(ok == 2)
    {
        if(strcmp(v[i].proprietar.nume, v[j].proprietar.nume) == 0)
            val = strcmp(v[i].proprietar.prenume, v[j].proprietar.prenume);
        else
            val = strcmp(v[i].proprietar.nume, v[j].proprietar.nume);
    }
    else if(ok == 3)
    {
        if(strcmp(v[i].marca, v[j].marca) == 0)
            val = strcmp(v[i].model, v[j].model);
        else
            val = strcmp(v[i].marca, v[j].marca);
    }
    else if(ok == 4)
    {
        if(strcmp(v[i].DataFabricare.an, v[j].DataFabricare.an) == 0)
        {
            if(strcmp(v[i].DataFabricare.luna, v[j].DataFabricare.luna) == 0)
                val = strcmp(v[i].DataFabricare.zi, v[j].DataFabricare.zi);
            else
                val = strcmp(v[i].DataFabricare.luna, v[j].DataFabricare.luna);
        }
        else
        {
            val = strcmp(v[i].DataFabricare.an, v[j].DataFabricare.an);
        }
    }
    if(x == 'd')
        val *= -1;
    return val;
}

int pivot(masina v[], int st, int dr, int ok, char x)
{
    int i = st, j = dr, di = 0, dj = 1;
    while(i < j)
    {
        if(compara(v, ok, i, j, x) > 0)
        {
            swap(v[i], v[j]);
            di = 1 - di;
            dj = 1 - dj;
        }
        i=i+di;
        j=j-dj;
    }
    return j;
}

void QuickSort(masina v[], int st, int dr, int ok, char x)
{
    if(st < dr)
    {
        int p = pivot(v, st, dr, ok, x);
        QuickSort(v, st, p-1, ok, x);
        QuickSort(v, p+1, dr, ok, x);
    }
}

void sortare(masina v[], int nr)
{
    int ok;
    do
    {
        system("CLS");
        cout << "Pentru sortare in functie de numarul de inmatriculare apasati 1" << endl;
        cout << "Pentru sortare in functie de nume si prenume proprietar apasati tasta 2" << endl;
        cout << "Pentru sortare in functie de marca si modelul masinii apasati tasta 3" << endl;
        cout << "Pentru sortare in functie de data de fabricare a masinii apasati tasta 4" << endl;
        cin >> ok;
        if(ok < 1 || ok > 4)
        {
            cout << "Ati introdus gresit!" << endl << "Incercati din nou!" << endl;
            cin.get();
            cin.get();
        }
    }while(ok < 1 || ok > 4);

    cout << "Daca vreti sa sortati crescator apasati tasta c: " << endl;
    cout << "Daca vreti sa sortati descrescator apasati tasta d: " << endl;
    char x;
    cin >> x;

    QuickSort(v, 0, nr - 1, ok, x);
    cin.get();

    switch(ok)
    {
        case 1: cout << "Informatiile au fost sortate in functie de numarul de imatriculare!"; break;
        case 2: cout << "Informatiile au fost sortate in functie de nume si prenume proprietar!"; break;
        case 3: cout << "Informatiile au fost sortate in functie de marca si modelul masinii!"; break;
        case 4: cout << "Informatiile au fost sortate in functie de data de fabricare a masinii!";
    }
    cin.get();
    ofstream f("BazaDeDate.dat");
    for(int i = 0; i < nr; i++)
    {
        f << v[i].marca << "|" << v[i].model << "|" << v[i].NrInmatriculare << "|" << v[i].culoare << "|";
        f << v[i].DataFabricare.zi << "." << v[i].DataFabricare.luna << "." << v[i].DataFabricare.an << "|";
        f << v[i].proprietar.nume << "|" << v[i].proprietar.prenume << endl;
    }
    f.close();
}

int CautareBinara(masina v[], int st, int dr, const char Inmatriculare[15])
{
    if(st <= dr)
    {
        int m = (st + dr) / 2;
        if(strcmp(v[m].NrInmatriculare, Inmatriculare) == 0)
        {
            return m;
        }
        else if(strcmp(v[m].NrInmatriculare, Inmatriculare) > 0)
        {
            CautareBinara(v, st, m - 1, Inmatriculare);
        }
        else
        {
            CautareBinara(v, m + 1, dr, Inmatriculare);
        }
    }
    else
    {
        return -1;
    }
}

void cautare(masina v[], int nr)
{
    masina Vehicul[nr];
    for(int i = 0; i < nr; i++)
    {
        Vehicul[i] = v[i];
    }
    QuickSort(Vehicul, 0, nr - 1, 1, 'c');

    char Inmatriculare[15];
    cout << "Introduceti numarul de inmatriculare al masinii cautate: ";
    cin >> Inmatriculare;
    int lungime = strlen(Inmatriculare);
    Inmatriculare[lungime] = ' '; Inmatriculare[lungime + 1] = '\0';
    int i = CautareBinara(Vehicul, 0, nr - 1, Inmatriculare);

    cin.get();
    if(i == -1)
    {
        cout << "Acest numar de inmatriculare nu exista in baza noastra de date!";
    }
    else
    {
        cout << Vehicul[i].marca << "|" << Vehicul[i].model << "|" << Vehicul[i].NrInmatriculare << "|" << Vehicul[i].culoare << "|";
        cout << Vehicul[i].DataFabricare.zi << "." << Vehicul[i].DataFabricare.luna << "." << Vehicul[i].DataFabricare.an << "|";
        cout << Vehicul[i].proprietar.nume << "|" << Vehicul[i].proprietar.prenume << endl;
    }
    cin.get();
    system("CLS");
}

void afisareMeniu()
{
    cout << "Pentru adaugare apasati tasta 1" << endl;
    cout << "Pentru inserare apasati tasta 2" << endl;
    cout << "Pentru stergere apasati tasta 3" << endl;
    cout << "Pentru cautare apasati tasta 4" << endl;
    cout << "Pentru sortare apasati tasta 5" << endl;
    cout << "Pentru a iesi din program apasati tasta 6" << endl;
}

void citireInitiala(masina v[1000], int& nr)
{
    ifstream f("BazaDeDate.dat");
    while(!f.eof())
    {
        f.getline(v[nr].marca, 20, '|');
        f.getline(v[nr].model, 20, '|');
        f.getline(v[nr].NrInmatriculare, 15, '|');
        f.getline(v[nr].culoare, 20, '|');
        f.getline(v[nr].DataFabricare.zi, 3, '.');
        f.getline(v[nr].DataFabricare.luna, 3, '.');
        f.getline(v[nr].DataFabricare.an, 15, '|');
        f.getline(v[nr].proprietar.nume, 50, '|');
        f.getline(v[nr].proprietar.prenume, 50, '\n');
        if(v[nr].marca[0])
        {
            nr++;
        }
    }
    f.close();
}

int main()
{
    masina ListaMasini[1000];
    int nrMasini = 0;

    citireInitiala(ListaMasini, nrMasini);

    int ok = 1;
    while(ok)
    {
        system("CLS");
        afisareMeniu();
        int tasta;
        cin >> tasta;
        switch(tasta)
        {
            case 1: adaugare(ListaMasini, nrMasini); break;
            case 2: inserare(ListaMasini, nrMasini); break;
            case 3: stergere(ListaMasini, nrMasini); break;
            case 4: cautare(ListaMasini, nrMasini); break;
            case 5: sortare(ListaMasini, nrMasini); break;
            case 6: ok = 0; break;
            default: ok = 0;
        }
    }
    return 0;
}
