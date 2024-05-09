#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node* next;
}node;

node* make_queue()
{
    node* q = (node*)malloc(sizeof(node)); //inicializa ponteiro para node
    q->next = NULL;
    return q;
}

node* push(node* last, int x)
{
    node* nm = make_queue(); //cria nó
    nm->next = last->next;
    last->next = nm;
    last->v = x;
    return nm;
    //novo nó virou o último e o valor foi colocado no antigo
}

void pop(node* f)
{
    f->next = f->next->next;
}

int main(){
    node* start = make_queue(); //nó de início (valor vazio, aponta pro primeiro nó)
    node* node = make_queue();
    start->next = node;

    node = push(node, 10);
    node = push(node, 5);
    node = push(node, 7);

    printf("%d\n", start->next->v);
    printf("%d\n", start->next->next->v);

    pop(start);

    printf("%d\n", start->next->v);

    return 0;
}
