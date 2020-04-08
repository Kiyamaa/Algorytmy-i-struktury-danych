#include <iostream>
#include <cmath>
using namespace std;

class Kolejka{
public:
    struct badacz{
        string imie;
        string nazwisko;
        int liczba;
        badacz *nastepny;
    };
    int n=0;
    badacz *last;
    badacz *akt;
    Kolejka();
    void push(string imie, string nazwisko, int liczba);
    void push_el(badacz *bad);
    void pop();
};
void find(Kolejka k1, Kolejka k2,int n, int v);

int main()
{
    int n,v, liczba;
    string imie, nazwisko;
    Kolejka k1;
    Kolejka k2;
    cin>>n>>v;                              //n-liczba badaczy, v-maksymalna dopuszczalna róznica między umiejętnościami
    for(int i=0;i<n/2;i++){
        cin>>imie>>nazwisko>>liczba;
        k1.push(imie, nazwisko, liczba);
    }
    for(int i=0;i<n/2;i++){
        cin>>imie>>nazwisko>>liczba;
        k2.push(imie, nazwisko, liczba);
    }

    find(k1,k2,n,v);
    return 0;
}

Kolejka::Kolejka(){
    last=nullptr;
}

void Kolejka::push(string imie, string nazwisko, int liczba)
{
    if(last==nullptr){
        badacz *pom=new badacz;
        pom->imie=imie;
        pom->liczba=liczba;
        pom->nazwisko=nazwisko;
        pom->nastepny=pom;
        last=pom;
    }
    else{
        badacz *pom=new badacz;
        pom->imie=imie;
        pom->liczba=liczba;
        pom->nazwisko=nazwisko;
        pom->nastepny=last->nastepny;
        last->nastepny=pom;
        last=pom;
    }
}

void Kolejka::push_el(Kolejka::badacz *bad)
{
    if(last==nullptr){
        badacz *pom=new badacz;
        pom->imie=bad->imie;
        pom->liczba=bad->liczba;
        pom->nazwisko=bad->nazwisko;
        pom->nastepny=pom;
        last=pom;
    }
    else{
        badacz *pom=new badacz;
        pom->imie=bad->imie;
        pom->liczba=bad->liczba;
        pom->nazwisko=bad->nazwisko;
        pom->nastepny=last->nastepny;
        last->nastepny=pom;
        last=pom;
    }
}

void Kolejka::pop()
{
    if(last->nastepny==last){
        last->nastepny=nullptr;
    }
    else{
        delete last->nastepny;
    last->nastepny=last->nastepny->nastepny;

    }
}

void find(Kolejka k1, Kolejka k2, int n, int v)
{
    int max1=0,max2=0,min1=1000,min2=1000,usuwany_el1,usuwany_el2,pom_index=-1, powt_max1=1,powt_max2=1, powt_min1=1, powt_min2=1;
    long long int srednia1=0,srednia2=0,sr1=0,sr2=0;
    for(int i=0;i<n/2;i++){

        usuwany_el1=k1.last->nastepny->liczba;
        usuwany_el2=k2.last->nastepny->liczba;
        if(i>0){
            k1.push_el(k2.last->nastepny);
            k2.push_el(k1.last->nastepny);
            k1.pop();
            k2.pop();
            sr1=sr1-usuwany_el1+k1.last->liczba;
            sr2=sr2-usuwany_el2+k2.last->liczba;
        }
        k1.akt=k1.last;
        k2.akt=k2.last;
        if(i==0){
            for(int i=0;i<n/2;i++){
                if(k1.akt->liczba>max1){
                    max1=k1.akt->liczba;
                    powt_max1=1;
                }
                if(k1.akt->liczba<min1){
                    min1=k1.akt->liczba;
                    powt_min1=1;
                }
                if(k2.akt->liczba>max2){
                    max2=k2.akt->liczba;
                    powt_max2=1;
                }
                if(k2.akt->liczba<min2){
                    min2=k2.akt->liczba;
                    powt_min2=1;
                }
                sr1+=k1.akt->liczba;
                sr2+=k2.akt->liczba;
                k1.akt=k1.akt->nastepny;
                k2.akt=k2.akt->nastepny;
            }
        }
        if(max1==usuwany_el1&&i>0){
            if(powt_max1==1){
            max1=k1.akt->liczba;
            for(int i=0;i<(n/2)-1;i++){
                if(k1.akt->nastepny->liczba>max1){
                    max1=k1.akt->nastepny->liczba;
                    powt_max1=1;
                }
                else if(k1.akt->nastepny->liczba==max1){
                    powt_max1++;
                }
                k1.akt=k1.akt->nastepny;
            }
            }
            else{
                powt_max1=powt_max1-1;
            }

        }
        if(max2==usuwany_el2&&i>0){
            if(powt_max2==1){
            max2=k1.akt->liczba;
            for(int i=0;i<(n/2)-1;i++){
                if(k2.akt->nastepny->liczba>max2){
                    max2=k1.akt->nastepny->liczba;
                    powt_max2=1;
                }
                else if(k2.akt->nastepny->liczba==max2){
                    powt_max2++;
                }
                k2.akt=k2.akt->nastepny;
            }
            }
            else powt_max2--;
        }
        if(min1==usuwany_el1&&i>0){
            if(powt_min1==1){
            min1=k1.akt->liczba;
            for(int i=0;i<(n/2)-1;i++){
                if(k1.akt->nastepny->liczba<min1){
                    min1=k1.akt->liczba;
                    powt_min1=1;
                }
                else if(k1.akt->nastepny->liczba==min1){
                    powt_min1++;
                }
                k1.akt=k1.akt->nastepny;
            }
            }
            else powt_min1--;
        }
        if(min2==usuwany_el2&&i>0){
            if(powt_min2==1){
            min2=k2.akt->liczba;
            for(int i=0;i<(n/2)-1;i++){
                if(k2.akt->nastepny->liczba<min2){
                    min2=k2.akt->nastepny->liczba;
                    powt_min2=1;
                }
                else if(k2.akt->nastepny->liczba==min2){
                    powt_min2++;
                }
                k2.akt=k2.akt->nastepny;
            }
            }
            else powt_min2--;
        }
        if(max2!=usuwany_el2&&min2!=usuwany_el2&&i>0){
            if(max1<k1.akt->liczba){
                max1=k1.akt->liczba;
            }
            if(min1>k1.akt->liczba){
                min1=k1.akt->liczba;
            }
            if(max2<k2.akt->liczba){
                max2=k2.akt->liczba;
            }
            if(min2>k2.akt->liczba){
                min2=k2.akt->liczba;
            }
        }
        if((max1-min1)<=v&&(max2-min2)<=v){
            if(srednia1==0&&srednia2==0){
                pom_index=i;
                srednia1=sr1;
                srednia2=sr2;
            }
            else if(abs(srednia1-srednia2)>abs(sr1-sr2)){
                pom_index=i;
                srednia1=sr1;
                srednia2=sr2;
            }
        }
    }
    if(pom_index>-1){

        for(int i=0;i<pom_index+1;i++){
            k1.push_el(k2.last->nastepny);
            k2.push_el(k1.last->nastepny);
            k1.pop();
            k2.pop();
        }
        k1.akt=k1.last->nastepny;
        k2.akt=k2.last->nastepny;
    for(int i=0;i<n/2;i++){
        cout<<k2.akt->imie<<" "<<k2.akt->nazwisko<<endl;
        k2.akt=k2.akt->nastepny;
    }
    cout<<endl;

    for(int i=0;i<n/2;i++){
        cout<<k1.akt->imie<<" "<<k1.akt->nazwisko<<endl;
        k1.akt=k1.akt->nastepny;
    }
    }
    else{
        cout<<"NIE";
    }
}