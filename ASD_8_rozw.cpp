#include <iostream>
using namespace std;
struct element{
    int p,w;                                         //p-numer panstwa, w-wspolczynnik panstwa
};

bool funkcja(int n, int miejsce, element tab[],int max){
    element *tab_wiek=new element[n];
    element *tab_mniej=new element[n];
    int l_wiek=0,l_mniej=0,l_row=0,granica=0;       //liczniki elementow wiekszych,mniejszych,rownych, max-wielkosc poczatkowej tablicy
    granica=n/2;                                    //wybranie elementu dzielacego
    int row=tab[granica].p;
    for(int i=0;i<n;i++){                                                               
        if(tab[i].w<tab[granica].w){
            tab_mniej[l_mniej].p=tab[i].p;
            tab_mniej[l_mniej].w=tab[i].w;
            l_mniej++;
        }
        if(tab[i].w==tab[granica].w){
            if(tab[i].p<row){
                row=tab[i].p;
            }
            l_row++;
        }
        if(tab[i].w>tab[granica].w){
            tab_wiek[l_wiek].p=tab[i].p;
            tab_wiek[l_wiek].w=tab[i].w;
            l_wiek++;
        }
    }
    if(n!=max){                                     //zwolnienie miejsca, przez usuniecie tablicy, jesli to nie tablica poczatkowa
        delete []tab;
    }
    if(l_mniej>=miejsce){
        delete []tab_wiek;
        funkcja(l_mniej,miejsce,tab_mniej,max);
        return 0;
    }
    if(l_mniej<miejsce&&(l_mniej+l_row)>=miejsce){
        delete []tab_mniej;
        delete []tab_wiek;
        cout<<row<<endl;
        return 0;
    }
    if(l_mniej+l_row<miejsce){
        delete []tab_mniej;
        funkcja(l_wiek,miejsce-l_mniej-l_row, tab_wiek,max);
        return 0;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m, miejsce;                   //n-liczba panstw, m-liczba zapytan
    cin>>n;
    element *tab=new element[n];
    for(int i=0;i<n;i++){
        cin>>tab[i].p>>tab[i].w;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>miejsce;
        funkcja(n,miejsce,tab,n);
    }
    delete []tab;
    return 0;
}