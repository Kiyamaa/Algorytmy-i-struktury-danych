#include <iostream>
#include <math.h>
struct Person{
    int czas;
    std::string nazwisko;
};

void SelectionSort(Person tab[], int n){
    Person pom;
    for(int i=n-1;i>0;i--){
        int min=0;
        for(int j=0;j<=i;j++){
            if(tab[j].czas<tab[min].czas||(tab[j].czas==tab[min].czas&&tab[j].nazwisko>tab[min].nazwisko)){
                min=j;
            }

        }
        pom=tab[i];
        tab[i]=tab[min];
        tab[min]=pom;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int t;                                          //liczba zestawow
    std::cin>>t;
    for(int i=0;i<t;i++){
        int n, p;                                   // n-liczba nazwisk, p-liczba nazwisk do wyswietlenia
        long long int wynik=1;
        std::cin>>n>>p;
        Person tab[n];                              //automatyczna tablica
        for(int j=0;j<n;j++){
            std::cin>>tab[j].nazwisko>>tab[j].czas;
        }
        SelectionSort(tab, n);
        for(int i=0;i<p;i++){
            std::cout<<tab[i].nazwisko<<" ";
        }
        for(int i=1;i<n;i++){
            wynik=wynik+1+tab[i].czas*i;
        }
        wynik=wynik%((long long int)(pow(10,6)+3));
        std::cout<<std::endl<<wynik<<std::endl;

    }
    return 0;
}