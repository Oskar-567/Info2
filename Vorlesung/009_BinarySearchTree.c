
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Array[] = {9,15,5,20,16,8,12,3,6};
int sizeA = sizeof(Array)/sizeof(Array[0]);

struct node
{
  int val;
  struct node* left;
  struct node* right;
};



//PRINT

#define MAX_HEIGHT 10    //Muss bei besonders vielen Elementen vergrösser werden
#define MAX_WIDTH 150

char treePrint[MAX_HEIGHT][MAX_WIDTH];

// Zeichenfläche zurücksetzen
void ClearPrintArea() {
  for (int i = 0; i < MAX_HEIGHT; i++) {
    memset(treePrint[i], ' ', MAX_WIDTH - 1);
    treePrint[i][MAX_WIDTH - 1] = '\0';
  }
}

// Rekursive Funktion zur Baumdarstellung mit Duplikaten
void DrawTreeDynamic(struct node* root, int depth, int xOffset, int spacing) {
  if (root == NULL || depth >= MAX_HEIGHT || xOffset < 0 || xOffset >= MAX_WIDTH)
    return;

  char buffer[10];
  sprintf(buffer, "%d", root->val);  // Wert des Knotens
  int nodeLen = strlen(buffer);
  int pos = xOffset - nodeLen / 2;

  // Wert in der Baumdarstellung zentrieren
  for (int i = 0; i < nodeLen && pos + i < MAX_WIDTH - 1; i++) {
    if (pos + i >= 0)
      treePrint[depth][pos + i] = buffer[i];
  }

  int newSpacing = spacing / 2;
  if (newSpacing < 1) newSpacing = 1;  // Verhindert Überlappen

  // Linker Teilbaum (Verbindung und Darstellung)
  if (root->left != NULL && depth + 2 < MAX_HEIGHT && xOffset - newSpacing >= 0) {
    DrawTreeDynamic(root->left, depth + 2, xOffset - newSpacing, newSpacing);
    if (depth + 1 < MAX_HEIGHT)
      treePrint[depth + 1][xOffset - newSpacing / 2] = '/';  // Verbindung zum linken Kind
  }

  // Rechter Teilbaum (Verbindung und Darstellung)
  if (root->right != NULL && depth + 2 < MAX_HEIGHT && xOffset + newSpacing < MAX_WIDTH) {
    DrawTreeDynamic(root->right, depth + 2, xOffset + newSpacing, newSpacing);
    if (depth + 1 < MAX_HEIGHT)
      treePrint[depth + 1][xOffset + newSpacing / 2] = '\\';  // Verbindung zum rechten Kind
  }
}

// Einstiegspunkt zur Baumdarstellung
void PrintTree(struct node* root) {
  ClearPrintArea();
  int initialSpacing = MAX_WIDTH / 4;  // Start-Abstand
  DrawTreeDynamic(root, 0, MAX_WIDTH / 2, initialSpacing);
  for (int i = 0; i < MAX_HEIGHT; i++) {
    printf("%s\n", treePrint[i]);
  }
}




//END PRINT



struct node* create()
{
  struct node *q;
  q = malloc(sizeof(struct node));
  q->val = 0;
  q->left = NULL;
  q->right = NULL;
  return q;
}

void VisitNode(struct node* p)
{
  if (p != NULL)
  {
    printf("%d ", p->val);
  }
  else {printf("Pointer ist NULL");}
}

struct node* createBST (struct node* p, int A[], int size)
{
  p->val = A[0];
  for(int i = 1; i < size; i++)
  {
    struct node* current = p;
    struct node* past = NULL;

    while (current != NULL)
     {
        past = current;
        if (A[i] < current->val) {current = current->left;}
        else {current = current->right;}
     }
    if (A[i] <= past->val)
     {
      past->left = create();
      past->left->val = A[i];
     }
    else
     {
      past->right = create();
      past->right->val = A[i];
     }
  }
  return p;

}

struct node* InorderTreeWalk(struct node *p)
{
  if (p != NULL)
  {
    InorderTreeWalk(p->left);
    VisitNode(p);
    InorderTreeWalk(p->right);
  }
}

struct node* BSTreeSearch(struct node *p, int key)
{
  while (p != NULL && p->val != key)
  {
    if (key < p->val) {p = p->left;}
    else {p = p->right;}
  }
  return p;
}

struct node* BSTreeMin(struct node* p)
{
  while (p->left != NULL) {p = p->left;}
  return p;
}

struct node* BSTreeSuccAbove(struct node* p, struct node* x)
{
  struct node* succ;
  succ = NULL;
  while (p != x)
  {
    if (x->val < p-> val)
    {
      succ = p;
      p = p->left;
    }
    else if (x->val > p->val) {p = p->right;}
  }
  return succ;
}

struct node* BSTreeInsert(struct node* p, struct node* r)
{
  struct node *y = NULL;
  struct node *x = r;
  while (x != NULL)
  {
    y = x;
    if (x->val < p->val) {x = x-> right;}
    else {x = x->left;}
  }

  if (y == NULL) {r = p;}
  else if (y->val < p->val) {y->right = p;}
  else {y->left = p;}
  return r;

}

int BSTreeCount(struct node* p, int key)
{
  if(p != NULL)
  {
    if(key < p->val) {return BSTreeCount(p->left, key);}
    else if (key > p->val) {return BSTreeCount(p->right, key);}
    else {return 1 + BSTreeCount(p->left, key) + BSTreeCount(p->right, key);}
  }
  return 0;
}

struct node* BSTreeDelete(struct node* root, struct node *x)
{
  struct node * cur = root;
  struct node * past = NULL;

  while (cur != x)        //Suchen des zu löschenden Knotens. Cur ist der zu löschende, past der vorangegangene Knoten.
  {                       //Falls curr = root ist past = NULL
    past = cur;
    if (x->val < cur->val) {cur = cur->left;}
    else {cur = cur->right;}
  }

  if (cur->right == NULL)  //Falls cur keine Rechte Node hat
  {
    if (past == NULL) {root = cur->left;}    //Wenn Cur = Root ist
    else if (past->left == cur) {past->left = cur->left;}    //Fügt cur bei past ein. Entweder links oder rechts, je nachdem, wo cur war.
    else past->right = cur->left;
  }
  else if (cur->left == NULL)    //Falls cur keine Linke Node hat
  {
    if (past == NULL) {root = cur->right;}   //Wenn Cur = Root ist
    else if (past->left == cur) {past->left = cur->right;}   //Fügt cur bei past ein. Entweder links oder rechts, je nachdem, wo cur war.
    else {past->right = cur->right;}
  }
  else          //Falls cur eine Rechte und ein Linke Node hat
  {
    struct node* p = x->left;  //Nachfolger node suchen
    struct node* q = p;        //Past Node von P

    while( p->right != NULL) {q = p; p = p->right;}  //Node mit dem grössten Wert im linken Teilbaum (einmal nach links und dann immer nach rechts gehen)

    if (past == NULL) {root = p;}    //Falls x root war
    else if (past->left == cur) {past->left = p;}
    else past->right = p;

    p->right = cur->right;    //rechter Teilbaum von x an p hängen
    if ( q != p)              //wenn p nicht direkt die linke node von x war
    {
      q->right = p->left;     //p hat eventuell eine linke node
      p->left = cur->left;    //x linker Teilbaum
    }
  }
  return root;
}

int main()
{
  struct node* root = create();
  createBST(root, Array, sizeA);
  printf("\n--- createBST ---\n");
  InorderTreeWalk(root);
  printf("\n");
  PrintTree(root);

  printf("\n--- BSTreeSearch ---\n");
  int search = 12;
  struct node* temp = BSTreeSearch(root, search);
  VisitNode(temp);

  printf("\n--- BSTreeMin ---\n");
  VisitNode(BSTreeMin(root));

  printf("\n--- BSTreeSuccAbove ---\n");
  if (temp != NULL) {VisitNode(BSTreeSuccAbove(root, temp));}
  else {printf("Search muss eine Zahl aus dem Tree sein!\n");}

  printf("\n--- BSTreeInsert ---\n");
  int B[] = {5, 6, 8, 25,50, 2 , 1 , 10, 13, 11};
  int sizeb = sizeof(B) / sizeof(B[0]);

  for (int i = 0; i < sizeb; i++)
  {
    struct node* add = create();
    add->val = B[i];
    root = BSTreeInsert(add, root);
  }
  InorderTreeWalk(root);
  printf("\n");
  PrintTree(root);

  printf("\n--- BSTreeCount ---\n");
  int key = 15;
  printf("%d is %d-times in BSTree", key, BSTreeCount(root, key));

  printf("\n--- BSTreeDelete ---\n");
  int delete = 20;
  temp = BSTreeSearch(root, delete);
  if (temp != NULL)
  {
    root = BSTreeDelete(root, temp);
    InorderTreeWalk(root);
    printf("\n\n");
    PrintTree(root);
  }
  else {printf("Delete muss eine Zahl aus dem Tree sein\n");}

}