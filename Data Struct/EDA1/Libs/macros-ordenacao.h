typedef int Item;
#define Key(A) (A) //Key(a) (A.chave) no caso de uma Struct
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) {Item t = A, A = B, B = t;}
#define cmpexch(A, B) {if(less(B, A) exch(A,B));}
