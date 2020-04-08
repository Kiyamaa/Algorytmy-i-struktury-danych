#include <iostream>

using namespace std;
bool porownaj(int tab[][2], bool *tab_pkt, int m, int poz, int l_wol, int pom){
    if(poz==m+1) return true;
    if(tab_pkt[tab[poz][0]]||tab_pkt[tab[poz][1]]){
        if(porownaj(tab,tab_pkt,m,poz+1,l_wol,pom)) return true;
    }
        if(tab_pkt[tab[poz][0]]==0&&tab_pkt[tab[poz][1]]==0&& pom<l_wol){
            tab_pkt[tab[poz][0]]=1;
            pom++;
            if(porownaj(tab,tab_pkt,m,poz+1,l_wol,pom)) return true;
            tab_pkt[tab[poz][0]]=0;
            tab_pkt[tab[poz][1]]=1;
            if(porownaj(tab,tab_pkt,m,poz+1,l_wol,pom)) return true;
            tab_pkt[tab[poz][1]]=0;
        }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    bool x=0;
    int t,n,m,r,a,b;                    // t-liczba zestawów danych, n-liczba stacji kolejowych, m-liczba odcinków kolejowych łączących dwie stacje
    cin>>t;                             // r-liczba wolontariuszy, a/b-numery stacji
    for(int i=0;i<t;i++){
        cin>>n>>m>>r;
        int tab[m+1][2];
        bool tab_pkt[m+1];
        for(int j=1;j<=m;j++){
            tab_pkt[j]=0;
            cin>>tab[j][0]>>tab[j][1];
        }
        x=porownaj(tab,tab_pkt, m, 1, r, 0);
        if(x) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
    return 0;
}