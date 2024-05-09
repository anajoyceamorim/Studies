#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

#define MAX 123456789

//utiliza a estrutura de fila

typedef struct node
{
    int v, cnt;
    struct node* next;
}node;

node* make_queue()
{
    node* q = (node*)malloc(sizeof(node)); //inicializa ponteiro para node
    q->next = NULL;
    return q;
}

node* push(node* last, int x, int y)
{
    node* nm = make_queue(); //cria nó
    nm->next = last->next;
    last->next = nm;
    last->v = x;
    last->cnt = y;
    return nm;
    //novo nó virou o último e o valor foi colocado no antigo
}

bool empty(node* f) {
    return f == NULL || f->next == NULL;
}

void pop(node* f)
{
    f->next = f->next->next;
}

int visited[MAX];
int main(){
    ll f, s, g, u, d;
    scanf("%lld %lld %lld %lld %lld", &f, &s, &g, &u, &d);

    // s = source, inicial
    // f = último andar (limite)

    node* start = make_queue();
    node* head = make_queue();
    start->next = head;
    node* curr = head;

    curr = push(curr, s, 0);
    visited[s]++;
    while(!empty(start)) {
        node* ps = front(start);
        pop(start);

        if(ps->v == q) {
            printf("%d\n");
            return 0;
        }

        if( u != 0 && ps->v + u <= f && !visited[ps->v + u]) {
            curr = push(curr, ps->v + u, ps->cnt + 1);
            visited[ps->v + u] = 1;
        }

        if (d != 0 && ps->v - d >= 1 && !visited[ps->v - d]){
            curr = push(curr, ps-> - d, ps->cnt + 1);
            visited[ps->v - d] = 1;
        }
    }

    printf("use the stairs\n");

    return 0;
}
