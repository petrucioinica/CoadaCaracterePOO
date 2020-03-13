#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Nod{
private:
char inf;
Nod *nxt;

public:
    Nod()
        {
        inf='0'; nxt=NULL;
        };
    ~Nod()
        {
        delete nxt;
        };
    char inf_get()
        {
        return inf;
        };
    Nod* nxt_get()
        {
        return nxt;
        };
    void inf_set(char x)
        {
        inf=x;
        };
    void nxt_set(Nod *x)
        {
        nxt=x;
        };
};

class Coada_de_caractere{
private:
    Nod *first,*last;
public:
    Coada_de_caractere(){
        first=NULL;last=NULL;
        };
    ~Coada_de_caractere()
    {   Nod *p,*q;
        p=first_get();
        q=last_get();
        delete p;
        delete q;
    };
    void first_set(Nod *p)
        {
        first=p;
        };
    void last_set(Nod *p)
        {
        last=p;
        };
    Nod* first_get() const
        {
        return first;
        };
    Nod* last_get()
        {
        return last;
        };
    void push(char x);
    void pop();
    int isempty();
    friend ostream& operator <<(ostream& os,const Coada_de_caractere &c);
    friend istream& operator>> (istream& is, Coada_de_caractere& c);
    friend Coada_de_caractere operator +(Coada_de_caractere &x, Coada_de_caractere &y);
    friend Coada_de_caractere operator -(Coada_de_caractere &x,Coada_de_caractere &y);
};

Coada_de_caractere operator -(Coada_de_caractere &x,Coada_de_caractere &y)
{
    Coada_de_caractere c;
    char inst[256];
    Nod *p,*q;
    int i=0,j;
    p=x.first_get();
    q=y.first_get();
    while(p!=NULL and q!=NULL)
    {
        if(p->inf_get()>q->inf_get())
            {
                inst[i]=p->inf_get();
                i++;
            }
        else
            {
                inst[i]=q->inf_get();
                i++;
            }
        p=p->nxt_get();
        q=q->nxt_get();
    }
    for(j=i-1;j>=0;j--)
        c.push(inst[j]);
    return c;
}


Coada_de_caractere operator +(Coada_de_caractere &x, Coada_de_caractere &y)
{

    x.last_get()->nxt_set(y.first_get());
    x.last_set(y.last_get());
    return x;
}


istream& operator>> (istream& is, Coada_de_caractere& c)
{
    cout<<"introduceti valori in coada. Cand nu mai doriti sa introduceti valori introduceti 0."<<endl;
    char x;
    is>>x;
    while(x!='0')
        {c.push(x);
        is>>x;}
    return is;
}

ostream& operator<<(ostream& os,const Coada_de_caractere &c)
    {
        Nod *p,*q;
        p=c.first_get();
        while(p!=NULL)
        {
            os<<p->inf_get();
            q=p;
            p=q->nxt_get();
            delete q;
        }
    delete p;
    return os;

};

void Coada_de_caractere::push(char x)
{
    Nod *p=new Nod;
    p->inf_set(x);
    p->nxt_set(NULL);
    if(isempty())
        first_set(p);
    else
        last->nxt_set(p);
        last_set(p);

};


void Coada_de_caractere::pop()
{
    Nod *p = new Nod;
    p=first_get();
    first_set(p->nxt_get());
    delete p;

}

int Coada_de_caractere::isempty()
{
    if (first_get() == NULL)
        return 1;
    else
        return 0;
}





int main()
{Coada_de_caractere coada1,coada2,coada;
    cin>>coada1;
    cin>>coada2;
    coada=coada1-coada2;
    cout<<coada;
    cout<<endl;
    coada=coada1+coada2;
    cout<<coada;

}
