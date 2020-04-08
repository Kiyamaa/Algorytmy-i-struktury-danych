#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,m,wwej, kwej, wwyj, kwyj;                     //wwej, kwej-wiersz, kolumna wejsciowa 'S', wwyj,kwyj- wiersz, kolumna wyjsciowa 'X'
    cin>>n>>m;
    char tab[n+2][m+2];
    for(int i=0;i<=n+1;i++){                            //wypełnienie mapy, pobranie wspolrzednych S i X, ogrodzenie mapy # aby nie wyjsc poza obszar
        for(int j=0;j<=m+1;j++){
            if(i!=0&&i!=n+1&&j!=m+1&&j!=0){
            cin>>tab[i][j];
            if(tab[i][j]=='S'){
                wwej=i;
                kwej=j;
            }
            if(tab[i][j]=='X'){
                wwyj=i;
                kwyj=j;
            }
            }
            else tab[i][j]='#';
        }
    }
    int licztab[n+2][m+2];
    int liczM[n+2][m+2];
    licztab[wwej][kwej]=0;
    liczM[wwej][kwej]=0;
    bool odwiedzone[n+2][m+2];
    bool odwiedzoneM[n+2][m+2];
    int w, k;
    queue<int> kol;
    kol.push(wwej);
    kol.push(kwej);
    while(!kol.empty()){

        w=kol.front();
        kol.pop();
        k=kol.front();
        kol.pop();
        if((w==wwyj)&&(k==kwyj)){
            break;
        }
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if((i==0&&j==1)||(i==0&&j==-1)||(i==1&&j==0)||(i==-1&&j==0)){
                    if((tab[w+i][k+j]!='#')&&(odwiedzone[w+i][k+j]!=true)){
                        kol.push(w+i);
                        kol.push(k+j);
                        odwiedzone[w+i][k+j]=true;
                        licztab[w+i][k+j]=licztab[w][k]+1;
                        liczM[w+i][k+j]=liczM[w][k];
                    }
                    if(((odwiedzone[w+i][k+j]==true)&&(licztab[w][k]+1<licztab[w+i][k+j]))){
                        licztab[w+i][k+j]=licztab[w][k]+1;
                        liczM[w+i][k+j]=liczM[w][k];
                    }
                    if((odwiedzone[w+i][k+j]==true)&&((licztab[w][k]+1)==licztab[w+i][k+j])&&(liczM[w][k]<liczM[w+i][k+j])&&(tab[w+i][k+j]!='M')){
                        liczM[w+i][k+j]=liczM[w][k];
                    }
                    if((odwiedzone[w+i][k+j]==true)&&((licztab[w][k]+1)==licztab[w+i][k+j])&&(liczM[w][k]<liczM[w+i][k+j])&&(tab[w+i][k+j]=='M')){
                        liczM[w+i][k+j]=liczM[w][k]+1;
                    }
                    if((tab[w+i][k+j]=='M')&&odwiedzoneM[w+i][k+j]!=true){
                        liczM[w+i][k+j]=liczM[w][k]+1;
                        odwiedzoneM[w+i][k+j]=true;
                    }
                }
            }
        }
    }
    cout<<licztab[wwyj][kwyj]<<" "<<liczM[wwyj][kwyj];
    return 0;
}