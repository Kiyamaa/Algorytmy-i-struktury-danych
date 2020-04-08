#include <iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,p,w,licz=0, ind;            //n-liczba panstw,p-nr panstawa,w-wspolcz panstwa,m-liczba zmian, licz-licznik zmian
    cin>>n;                             //liczba panstw
    int tab[n][2];                      //tablica panstw
    int tab_id[1001]={0};               //tablica indeksow panstw o danym id
    for(int i=0;i<n;i++){
        cin>>tab[i][0]>>tab[i][1];      //wczytywanie danych
        tab_id[tab[i][0]]=i;
    }
    cin>>m;
    for(int i=0;i<m;i++){               //wczytywanie zmian
        cin>>p>>w;
        ind=tab_id[p];
        tab[ind][1]=w;
        //przesiewanie w gore
        if(ind>0&&tab[ind][1]>tab[(ind-1)/2][1]){
            while(ind>0&&tab[(ind-1)/2][1]<tab[ind][1]){
                int pom=(ind-1)/2;
                swap(tab[ind], tab[(ind-1)/2]);
                swap(tab_id[tab[ind][0]], tab_id[tab[pom][0]]);
                ind=(ind-1)/2;
                licz++;
            }
        }
        //przesiewanie w dol
        if(ind*2+1<n&&(tab[ind][1]<tab[ind*2+1][1]||tab[ind][1]<tab[ind*2+2][1])){                  
            while(ind*2+1<n&&(tab[ind][1]<tab[ind*2+1][1]||tab[ind][1]<tab[ind*2+2][1])){
                if(tab[ind][1]<tab[ind*2+1][1]&&(tab[ind*2+1][1]>=tab[ind*2+2][1]||ind*2+2>=n)){
                    swap(tab_id[tab[ind][0]],tab_id[tab[ind*2+1][0]]);
                    swap(tab[ind], tab[ind*2+1]);
                    ind=ind*2+1;
                    licz++;
                }
                else if(ind*2+2>=n){
                    break;
                }
                else if(tab[ind][1]<tab[ind*2+2][1]){
                    swap(tab_id[tab[ind][0]], tab_id[tab[ind*2+2][0]]);
                    swap(tab[ind], tab[ind*2+2]);
                    ind=ind*2+2;
                    licz++;
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<licz;
    return 0;
}
