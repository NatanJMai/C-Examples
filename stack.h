/* Natan J. Mai
 * Last In First Out (LIFO)
 * */

typedef struct node{
  struct node* prev;
  struct node* next;
  char* name;
  int  id;
} node;

typedef struct{
  node *first;
  node *last;
  int  qtd;
  int  id;
} stack;

stack * initStack(int id){
  stack *s;

  s = malloc(sizeof(stack));
  s->id = id;
  return s;
}

node * initNode(char *n, int i){
  node *nd;
  
  nd = malloc(sizeof(node));
  nd->name = n;
  nd->id   = i;

  return nd;
}

void pop(stack *st){
  node *f, *aux;

  f = st->first;

  aux = f->next;
  aux->prev = NULL;

  st->first = aux;
  st->qtd--;

  f->next = NULL;
  f->prev = NULL;
}

void push(stack *st, node *nd){
  node *first = st->first;
  node *aux;

  if(st->qtd <= 0){
    st->first = nd;
    st->last  = nd;
    
    nd->prev = NULL;
    nd->next = NULL;
    st->qtd = 1;
    return;
  }

  aux = st->first;

  nd->prev = NULL;
  nd->next = aux;

  aux->prev = nd;
  
  st->first = nd;
  st->qtd++;
  return;
}

void print(stack *st){
  int i = 0;
  node *n, *l;

  n = st->first;
  l = st->last;

  while(i < st->qtd){
    printf("NAME -> %s | ID -> %d\n", n->name, n->id);
    n = n->next;
    i++;
  }
}

int test001(stack *s){
  int i;
  node  *n;
//  stack *s = initStack(0);
  
  for(i = 0; i < 20; i++){
    n = initNode("natan", i);
    push(s, n);
  }

  for(i = 0; i < 5; i++)
    pop(s);
 
  print(s);
  free(s);
  free(n);
}

int test002(stack *q){
  int i;
  node *t;
//  stack *q = initStack(1);

  for(i = 0; i < 2; i++){
    t = initNode("natan", i);
    push(q, t);
  }

  for(i = 0; i < 1; pop(q), i++);

  print(q);
  free(q);
  free(t);
}

int test003(stack *j){
  int i;
  node *n;

  for(i = 0; i < 22; i++){
    n = initNode("natan", i);
    push(j, n);
  }

  for(i = 0; i < 10; pop(j), i++);
  print(j);
  free(j);
  free(n);
}

int runTest(){
  stack *s, *t, *q;

  s = initStack(1);
  t = initStack(2);
  q = initStack(3);

  test001(s);
  printf("\n-------TEST 002-----------\n");
  test002(t);
  printf("\n-------TEST 003-----------\n");
  test003(q);
  

}
