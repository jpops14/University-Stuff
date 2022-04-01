#include "mytable.h"


struct tablica * nowa_tablica()
{
    struct tablica * newtab=(struct tablica *)malloc(sizeof(struct tablica));
    newtab->L=0;
    newtab->R=0;
    newtab->length=0;
    newtab->shift=0;
    newtab->tab=NULL;
    return newtab;
}

dane indeks(struct tablica * t,int position)
{
    if((t->length)==0)
    {
        printf("error - empty array\n");
        return 0;
    }
    if(position<(t->L)||position>(t->R))
    {
        printf("error - out of bounds\n");
        return 0;
    }
    else return t->tab[position+t->shift];
}

void dodaj(struct tablica * t, int pos, dane elem)
{
    if(t->length==0)
    {
        t->length=1;
        t->L=pos;
        t->R=pos;
        t->shift=(-1)*pos;
        t->tab= (dane *)calloc(1,sizeof(dane));
        t->tab[0]=elem;
    }
    else if(pos<(t->L))
    {
        int temp=(t->L)-pos;
        t->length+=temp;
        t->tab=realloc(t->tab,(sizeof(dane))*(t->length));
        for(int i=(t->length)-1;i>=temp;i--)
           t->tab[i]=t->tab[i-temp];
        for(int i=1;i<temp;i++)
           t->tab[i]=0;
        t->tab[0]=elem;
        t->L=pos;
        t->shift=(-1)*pos;


    }
    else if(pos>(t->R))
    {
        int temp=pos-(t->L)+1;
        t->tab=realloc(t->tab,(sizeof(dane))*temp);
        for(int i=t->length; i<temp-1; i++)
            t->tab[i]=0;
        t->tab[temp-1]=elem;
        t->length=temp;
        t->R=pos;
    }
    else t->tab[pos+(t->shift)]=elem;

}
