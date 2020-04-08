#include <iostream>
#include <list>
#include <map>
using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    int t,m,n;
    string nazw1,nazw2,wyraz;
    cin>>t;
    map<string, int> mapa;                  
    map<string, int>::iterator iter;
    map<string, int> mapa_konc;             //mapa wyrazow wykorzystanych
    std::list<string>::iterator it;
    string wyr;
    for(int i=0;i<t;i++){
            cin>>n>>m;
            mapa.clear();
            mapa_konc.clear();
            list<string> tab[n];            //tablica list kolejnosci wyrazow
            int prawda=0;
        for(int j=0;j<n;j++){               //dodawanie do wyrazu do mapy
            cin>>wyr;
            mapa[wyr]=j;
        }
        for(int j=0;j<m;j++){               //dodawanie do listy kolejnosci
            int poz=0;
            cin>>nazw1>>nazw2;
            iter=mapa.find(nazw1);
            poz=iter->second;
            tab[poz].push_back(nazw2);
        }
        for(int j=0;j<n;j++){               //szukanie wyraz z wynikowej listy w mapie
           int k=0;
           cin>>wyraz;
           mapa_konc[wyraz]=j;
           iter=mapa.find(wyraz);
           k=iter->second;
           it=tab[k].begin();           
           while(it!=tab[k].end()){             //sprawdzanie poprawnosci kolejnosci
               if(!tab[k].empty()){
                   int pom=0;
                   iter=mapa_konc.find(*it);
                   if(iter!=mapa_konc.end()){
                           pom=1;
                   }
                   if(pom==1) {                 //zla kolejnosc, przerwij
                       prawda=1;
                       break;
                   }
               }
               it++;

            }
           mapa.erase(wyraz);
           if(prawda==1){
               for(int h=j+1;h<n;h++){
                   cin>>wyraz;
               }
               cout<<"NIE"<<endl;
               break;
           }
        }
        if(prawda==0){
            cout<<"TAK"<<endl;
        }

    }
    return 0;
}