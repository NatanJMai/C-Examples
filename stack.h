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
} stack;

stack * initStack(){
  return (stack *) malloc(sizeof(stack));
}

node * initNode(char *n, int i){
  node *nd;
  
  nd = malloc(sizeof(node));
  nd->name = n;
  nd->id   = i;

  return nd;
}

node * pop(stack *st){
  node *f, *aux;

  f = st->first;

  aux = f->next;
  aux->prev = NULL;

  st->first = aux;
  st->qtd--;

  f->next = NULL;
  f->prev = NULL;

  return f;
}

int push(stack *st, node *nd){
  node *first = st->first;
  node *aux;

  if(first == NULL){
    st->first = nd;
    st->last  = nd;
    
    nd->prev = NULL;
    nd->next = NULL;
    st->qtd++;
    return 1;
  }

  aux = st->first;

  nd->prev = NULL;
  nd->next = aux;

  aux->prev = nd;
  
  st->first = nd;
  st->qtd++;
  return 1;
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

int test001(){
  int i;
  node  *n;
  stack *s = initStack();
  
  for(i = 0; i < 100; i++){
    n = initNode("natan", i);
    push(s, n);
  }
 
  print(s);
}

int runTest(){
  test001();

}
