#include <list>
using namespace std;

struct element{
    int cytuje,zrodlo,dzien;
};

int main()
{
    ios_base::sync_with_stdio(false);
    int l_med, s, d, l_d, m;
    int a,b1,c,b2;
    long long int pom, licz=1;
    std::list<element> lista[7];
    std::list<element>::iterator it;
    cin>>l_med>>s>>d>>l_d>>m;
    long long int tab[l_med][7];
    for(int i=0;i<l_med;i++){
        for(int j=0;j<7;j++){
            tab[i][j]=0;
        }
    }
    tab[s][d]=1;
    for(int i=0; i<m;i++){
        cin>>a>>b1>>c>>b2;
        element el;
        el.cytuje=a;
        el.zrodlo=c;
        el.dzien=b2;
        lista[b1].push_back(el);
    }

    for(int i=d+1;i<d+l_d;i++){
        pom=i%7;
        if(!lista[pom].empty()){
            for(int j=0;j<l_med;j++){
                tab[j][pom]=0;
            }
            for(it=lista[pom].begin();it!=lista[pom].end();it++){
                if(tab[it->zrodlo][it->dzien]!=0){
                    tab[it->cytuje][pom]+=tab[it->zrodlo][it->dzien]%100000007;
                    licz+=tab[it->zrodlo][it->dzien]%100000007;
            }
        }
        }
    }
    cout<<(licz)%100000007;
    return 0;
}