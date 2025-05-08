#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Array[] = {1,9,15,5,20,16,8,12,3,6};
int sizeA = sizeof(Array)/sizeof(Array[0]);

int ArrayB[] = {13,7,22,5,17,2,25,10,19,3};
int sizeB = sizeof(ArrayB)/sizeof(ArrayB[0]);

struct node
{
  int val;
  int hgt;
  struct node* left;
  struct node* right;
};

struct node* root = NULL;



//PRINT

#define MAX_HEIGHT 13    //Muss bei besonders vielen Elementen vergrösser werden
#define MAX_WIDTH 150

int BF(struct node* p);

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

void DrawTreeBFsDynamic(struct node* root, int depth, int xOffset, int spacing) {
  if (root == NULL || depth >= MAX_HEIGHT || xOffset < 0 || xOffset >= MAX_WIDTH)
    return;

  char buffer[10];
  sprintf(buffer, "%d", BF(root));  // ← HIER: Balance-Faktor ausgeben!
  int nodeLen = strlen(buffer);
  int pos = xOffset - nodeLen / 2;

  for (int i = 0; i < nodeLen && pos + i < MAX_WIDTH - 1; i++) {
    if (pos + i >= 0)
      treePrint[depth][pos + i] = buffer[i];
  }

  int newSpacing = spacing / 2;
  if (newSpacing < 1) newSpacing = 1;

  if (root->left != NULL && depth + 2 < MAX_HEIGHT && xOffset - newSpacing >= 0) {
    DrawTreeBFsDynamic(root->left, depth + 2, xOffset - newSpacing, newSpacing);
    if (depth + 1 < MAX_HEIGHT)
      treePrint[depth + 1][xOffset - newSpacing / 2] = '/';
  }

  if (root->right != NULL && depth + 2 < MAX_HEIGHT && xOffset + newSpacing < MAX_WIDTH) {
    DrawTreeBFsDynamic(root->right, depth + 2, xOffset + newSpacing, newSpacing);
    if (depth + 1 < MAX_HEIGHT)
      treePrint[depth + 1][xOffset + newSpacing / 2] = '\\';
  }
}

void PrintTreeBFs(struct node* root) {
  ClearPrintArea();
  int initialSpacing = MAX_WIDTH / 4;
  DrawTreeBFsDynamic(root, 0, MAX_WIDTH / 2, initialSpacing);
  for (int i = 0; i < MAX_HEIGHT; i++) {
    printf("%s\n", treePrint[i]);
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


void VisitNode(struct node* p)
{
  if (p != NULL)
  {
    printf("%d ", p->val);
  }
  else {printf("Pointer ist NULL");}
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




int height(struct node* p)
{
  if (p == NULL) return 0;
  return p->hgt;
}

 /*

int max(int a, int b) {
    return (a > b) ? a : b; 	//"Wenn a größer als b ist, gib a zurück, sonst gib b zurück."
}

 */

int max(int a, int b)
{
  if (a > b) {return a;}
  else {return b;}
}


int BF(struct node* p)
{
  if (p == NULL) return 0;
  return height(p->right) - height(p->left);
}


struct node* rgtRot(struct node* x)
{
  struct node *y;
  y = x->left;

  struct node *B = y->right;
  y->right = x;
  x->left = B;
  y->hgt = max(height(y->left), height(y->right)) + 1;
  x->hgt = max(height(x->left), height(x->right)) + 1;
  return y;
}

struct node* lftRot(struct node* x)
{
  struct node *y;
  y = x->right;

  struct node *B = y->left;
  y->left = x;
  x->right = B;
  x->hgt = max(height(x->left), height(x->right)) + 1;
  y->hgt = max(height(y->left), height(y->right)) + 1;
  return y;
}

struct node* AVLrebalance(struct node* p)
{
  p->hgt = max(height(p->left), height(p->right)) + 1;

  int bal = BF(p);
  if ((bal < -1) && BF(p->left) <= 0) 				//LL case
  {
    return rgtRot(p);
  }
  if ((bal > 1) && BF(p->right) >= 0) {return lftRot(p);}		//RR case

  if ((bal < -1) && BF(p->left) > 0)
  {
    p->left = lftRot(p->left);
    return rgtRot(p);
  }

  if ((bal > 1) && BF(p->left) < 0)
  {
    p->right = rgtRot(p->right);
    return lftRot(p);
  }
  return p;
}

struct node* AVLins(struct node *p, int k)
{
  if (p == NULL)
  {
    p = malloc(sizeof(struct node));
  	p->val = k;
  	p->left = NULL;
  	p->right = NULL;
  }
  else if (k < p->val) {p->left = AVLins(p->left, k);}
  else if (k > p->val) {p->right = AVLins(p->right, k);}
  return AVLrebalance(p);
}

struct node* AVLdel(struct node *p, int k)
{
  if (p == NULL) return NULL;  // sonst Absturz

  if (k < p->val) {p->left = AVLdel(p->left, k);}
  else if (k > p->val) {p->right = AVLdel(p->right, k);}
  else
  {
    if (p->left == p->right) {free(p); return NULL;}	//Leaf
    else if (p->left == NULL) 							//No left child
    {
      struct node *q = p;
      p = p->right;
      free(q);
    }
    else if (p->right == NULL) 							//No right child
    {
      struct node *q = p;
      p = p->left;
      free(q);
    }
    else
    {
      struct node *q = p->left;
      while (q->right != NULL) {q = q->right;}
      p->val = q->val;									//Bisschen unsauber mit dem kopieren der Values. Besser Pointer verändern.
      p->left = AVLdel(p->left, q->val);
    }
  }
  return AVLrebalance(p);
}

int main()
{

  for (int i = 0; i < sizeA; i++)
  {
    root = AVLins(root, Array[i]);
  }
  printf("\n--- AVL Tree ---\n");
  InorderTreeWalk(root);
  printf("\n");
  PrintTree(root);
  printf("\n--- Balance-Faktoren ---\n");
  PrintTreeBFs(root);

  root = AVLdel(root, 5);
  root = AVLdel(root, 9);

  printf("\n--- Nach Deletion ---\n");
  InorderTreeWalk(root);
  printf("\n");
  PrintTree(root);
  printf("\n--- Balance-Faktoren ---\n");
  PrintTreeBFs(root);

  for (int i = 0; i < sizeB; i++)
  {
    root = AVLins(root, ArrayB[i]);
  }
  printf("\n--- AVLins ---\n");
  InorderTreeWalk(root);
  printf("\n");
  PrintTree(root);
  printf("\n--- Balance-Faktoren ---\n");
  PrintTreeBFs(root);


}