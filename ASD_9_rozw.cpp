#include <iostream>
using namespace std;

unsigned long long int euklides(unsigned long long int e, unsigned long long int fi){
    unsigned long long int fi_pom=fi;
    long long int x=0, y=1;
    while(e){
        if(e<fi){
            swap(y,x);
            swap(fi, e);
        }
        y=y-((e/fi)*x);
        e=e%fi;        //reszta z dzielenia
    }
    if(x<0){
        x=x+fi_pom;
    }
    return x;
}
unsigned long long int pot_wiel_kwadratow_mod(unsigned long long int liczba, unsigned long long int potega, unsigned long long int mod){
    unsigned long long int wynik;
    if(potega==0) return 1;
    if(potega%2) {
        return liczba *pot_wiel_kwadratow_mod(liczba,potega-1,mod)%mod;
    }
    else{
         wynik=pot_wiel_kwadratow_mod(liczba, potega/2,mod)%mod;
    }
    return (wynik*wynik)%mod;
}

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned long long int p,q,e,c,n,d,fi,wartosc;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>p>>q>>e>>c;
        n=p*q;
        fi=(p-1)*(q-1);
        d=euklides(e,fi);
        wartosc=pot_wiel_kwadratow_mod(c,d,n);
        cout<<wartosc<<endl;
    }
    return 0;
}