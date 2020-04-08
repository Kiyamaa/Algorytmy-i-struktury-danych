#include <iostream>
using namespace std;
class Lista{
public:
    struct element{
        string wyraz;
        int x, y;
        element *next;
        element *previous;
    };
    int n=0;
    element *first;
    element *last;
    element *current;
    element *pom=nullptr;
    Lista();
    bool empty();
    void insert_prev(element *obj);
    void erase(element *pom);
    void push_back(int x, string wyraz);
    void push_back2(int x, int y, string wyraz);
    void move(int x);
};
int main()
{
    std::ios::sync_with_stdio(false);
    int n,s,x,y,p;
    string wyraz;
    Lista l1;
    Lista l2;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>wyraz>>x;
        l1.push_back(x,wyraz);
    }
    cin>>p;
    for(int i=0;i<p;i++){
        cin>>wyraz>>x>>y;
        l2.push_back2(x,y,wyraz);
    }
    l1.current=l1.first;
    if(s!=0){
        l1.move(s);
    }
    while(l1.empty()==false){
        if(l1.current->x!=0){
            if(l1.n==1){
                cout<<l1.first->wyraz;
                l1.erase(l1.first);
            }
            else{
            cout<<l1.current->wyraz<<" ";
            l1.pom=l1.current;
            if(l1.current->x%(l1.n-1)>0&&l1.current->x%(l1.n-1)>(l1.n/2)){
                l1.move(-((l1.n)-l1.current->x%(l1.n-1)));
            }
            else if(l1.current->x%(l1.n-1)<0&&l1.current->x%(l1.n-1)<(-l1.n/2)){
                l1.move((l1.n)+(l1.current->x%(l1.n-1)));
            }
            else{
                l1.move(l1.current->x%(l1.n-1));
            }
            l1.erase(l1.pom);
            }
        }
        else{
            l1.insert_prev(l2.first);
            l1.current->x=l2.first->y;
            if(l1.current->x%(l1.n)!=0){
                if(l1.current->x%(l1.n)>0&&l1.current->x%(l1.n)>(l1.n/2)){
                    l1.move(-((l1.n)-l1.current->x%(l1.n)));
                }
                else if(l1.current->x%(l1.n)<0&&l1.current->x%(l1.n)<(-l1.n/2)){
                    l1.move((l1.n)+(l1.current->x%(l1.n)));
                }
                else{
                    l1.move(l1.current->x%(l1.n));
                }
            }
            l2.current=l2.first;
            l2.erase(l2.first);
        }
    }
    return 0;
}

Lista::Lista(){
    first=nullptr;
    last=nullptr;
    current=nullptr;
}

bool Lista::empty(){
    if (n==0) return true;
    else return false;
}
void Lista::insert_prev(element *obj)
{
    element *pom2=new element;
    pom2->x=obj->x;
    pom2->wyraz=obj->wyraz;
    pom2->previous=current->previous;
    pom2->next=current;
    current->previous=pom2;
    current->previous->previous->next=pom2;
    n++;
}

void Lista::erase(element *pom)
{
    if(pom==first){
        first=pom->next;
    }
    else if(pom==last){
        last=pom->previous;
    }
    pom->previous->next=pom->next;
    pom->next->previous=pom->previous;
    delete pom;
    n--;
}

void Lista::push_back(int x, string wyraz){
    if(first==nullptr){
        element *pom=new element;
        pom->x=x;
        pom->wyraz=wyraz;
        first=pom;
        last=first;
        first->next=last;
        first->previous=last;
        last->next=first;
        last->previous=first;
        n++;
    }
    else{
        element *pom=last;
        pom->next=new element;
        pom->next->x=x;
        pom->next->wyraz=wyraz;
        pom->next->previous=pom;
        pom->next->next=first;
        last=pom->next;
        first->previous=last;
        n++;
    }
}

void Lista::push_back2(int x, int y, string wyraz){
    if(first==nullptr){
        element *pom=new element;
        pom->x=x;
        pom->wyraz=wyraz;
        pom->y=y;
        first=pom;
        last=first;
        first->next=last;
        first->previous=last;
        last->next=first;
        last->previous=first;
        n++;
    }
    else{
        element *pom=last;
        pom->next=new element;
        pom->next->x=x;
        pom->next->y=y;
        pom->next->wyraz=wyraz;
        pom->next->previous=pom;
        pom->next->next=first;
        last=pom->next;
        first->previous=last;
        n++;
    }
}

void Lista::move(int x)
{
    if(x==0&&current->x>0){
        current=current->previous;
    }
    else if (x==0&&current->x<0){
        current=current->next;
    }
    else if(x>0){
        int j=0;
        while(j!=x){
            current=current->next;
            j++;
        }
    }
    else if (x<0){
        int j=0;
        while(j!=x){
            current=current->previous;
            j--;
        }
    }
}