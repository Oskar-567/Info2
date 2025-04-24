#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ArrayA[] = {9, 3, 10, 6, 12, 1, 8};
int sizeA = (sizeof(ArrayA)/sizeof(ArrayA[0]));

/*

        9
       / \
      3   10
     / \     \
    1   6     12
         \
          8

 */
#define MAX_SIZE 100

int InOrder[MAX_SIZE];
int PreOrder[MAX_SIZE];
int PostOrder[MAX_SIZE];
int preIndex = 0, inIndex = 0, postIndex = 0;


struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct StackNode
{
  struct TreeNode* treeNode;
  struct StackNode* next;
};


struct TreeNode* insert(struct TreeNode** root, int val)
{
  if (*root == NULL)
  {
    struct TreeNode* q = malloc(sizeof(struct TreeNode));
    q->val = val;
    q->left = NULL;
    q->right = NULL;
    *root = q;
    return q;         //Wichtig hier, falls root==NULL, denn ansonsten läuft die funktion danahc in die if Schleife und wird nicht abgebrochen. Da mit Doppelpointern gearbeitet wird, ist generell eigendlich kein return notwendig.
  }
  if (val < (*root)->val) {return insert(&(*root)->left, val);}
  else {return insert(&(*root)->right, val);}
}

void traverseTree(struct TreeNode* root)
{
  if (root != NULL)
  {
    PreOrder[preIndex++] = root->val;
    traverseTree(root->left);
    InOrder[inIndex++] = root->val;
    traverseTree(root->right);
    PostOrder[postIndex++] = root->val;
  }
}

void printArray(int A[], int size)
{
  for (int i = 0; i < size; i++) {printf("%d ",A[i]);}
  printf("\n");
}


// Stack functions
void push(struct StackNode** top_ref, struct TreeNode* t)
{
    struct StackNode* new_node = (struct StackNode*)malloc(sizeof(struct StackNode));
    new_node->treeNode = t;
    new_node->next = (*top_ref);		//Last in First out. New Node wird an erste Stelle im Stack gesetzt.
    (*top_ref) = new_node;				//Pointer top_ref zeigt nun auf die erste Node new_node. Wenn man mit Pointer Pointer arbeitet, kann ich die Liste direkt ändern und muss nicht den neuen Pointer returnen.
}										//Klammern notwendig, da ansonsten eine Multiplikation ausgeführt werden würde

int isEmpty(struct StackNode* top)
{
    return (top == NULL);
}

struct TreeNode* pop(struct StackNode** top_ref)
{
    struct TreeNode* res;
    struct StackNode* top;

    if (isEmpty(*top_ref)) return NULL;

    top = *top_ref;
    res = top->treeNode;
    *top_ref = top->next;		//Klammern nicht notwendig, da dier -> Operator zuerst ausgewertet wird und erst danach der * Operator
    free(top);
    return res;
}


void stack_traverseTree(struct TreeNode* root)
{
  //Pre Order
  printf("\nstack_traverseTree \n");
  printf("Pre-order: ");

  struct StackNode* stack = NULL;
  struct TreeNode* curr = root;

  while (curr != NULL || !isEmpty(stack))
  {
    printf("%d ", curr->val);

    if (curr->right != NULL)					// Falls der aktuelle Knoten ein rechtes Kind hat, push es auf den Stack
    {
      push(&stack, curr->right);
    }
    curr = curr->left;							// Gehe zum linken Kind des aktuellen Knotens
    if (curr == NULL && !isEmpty(stack))		// Falls kein linkes Kind vorhanden ist, pop vom Stack
    {
      curr = pop(&stack);
    }

  }



  //In Order
  printf("\nIn-order: ");

  stack = NULL;
  curr = root;

  while (curr != NULL || !isEmpty(stack))
  {
        // Reach the leftmost node of the curr node
        while (curr != NULL)
        {
            push(&stack, curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = pop(&stack);
        printf("%d ", curr->val);  // Visit the node

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        curr = curr->right;
  }


  //Post Order
  printf("\nPost-order: ");

  stack = NULL;
  curr = root;
  struct StackNode* output = NULL;  // Hilfsstack für die Postorder-Reihenfolge

    // Stack für die Iteration
    push(&stack, curr);

    while (!isEmpty(stack)) {
        curr = pop(&stack);  // Hole den aktuellen Knoten aus dem Stack
        push(&output, curr);  // Füge den Knoten in den Output-Stack hinzu

        // Zuerst das linke Kind, dann das rechte Kind, weil wir später in umgekehrter Reihenfolge verarbeiten
        if (curr->left != NULL) {
            push(&stack, curr->left);
        }

        if (curr->right != NULL) {
            push(&stack, curr->right);
        }
    }

    // Jetzt haben wir die Knoten in umgekehrter Reihenfolge der Postorder
    // Wir müssen sie aus dem Output-Stack in Postorder ausgeben
    while (!isEmpty(output)) {
        curr = pop(&output);
        printf("%d ", curr->val);
    }
}

// Hilfsfunktion: Den kleinsten Knoten im rechten Teilbaum finden (Inorder-Nachfolger)
struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    // Gehe zum äußersten linken Knoten
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* delete(struct TreeNode** root, int val) {
    // Wenn der Baum leer ist, gebe NULL zurück
    if (*root == NULL) {
        return NULL;
    }

    // Gehe zum linken oder rechten Unterbaum, je nach Wert
    if (val < (*root)->val) {
        (*root)->left = delete(&(*root)->left, val);  // Rekursiver Aufruf für den linken Unterbaum
    } else if (val > (*root)->val) {
        (*root)->right = delete(&(*root)->right, val);  // Rekursiver Aufruf für den rechten Unterbaum
    } else {
        // Knoten gefunden, der gelöscht werden muss
        struct TreeNode* temp = *root;

        // Fall 1: Der Knoten hat kein oder nur ein Kind
        if ((*root)->left == NULL) {
            *root = (*root)->right;  // Das rechte Kind (oder NULL) wird an die Stelle des aktuellen Knotens gesetzt
            free(temp);  // Freigabe des aktuellen Knotens
        } else if ((*root)->right == NULL) {
            *root = (*root)->left;  // Das linke Kind (oder NULL) wird an die Stelle des aktuellen Knotens gesetzt
            free(temp);  // Freigabe des aktuellen Knotens
        } else {
            // Fall 2: Der Knoten hat zwei Kinder
            // Finde den Inorder-Nachfolger (der kleinste Knoten im rechten Teilbaum)
            struct TreeNode* successor = minValueNode((*root)->right);

            // Kopiere den Wert des Inorder-Nachfolgers in den aktuellen Knoten
            (*root)->val = successor->val;

            // Lösche den Inorder-Nachfolger aus dem rechten Teilbaum
            (*root)->right = delete(&(*root)->right, successor->val);
        }
    }

    return *root;
}









int main()
{
  struct TreeNode* p = NULL;
  for (int i = 0; i < sizeA; i++)
  {
    insert(&p, ArrayA[i]);
  }

  traverseTree(p);

  printf("Pre-order: ");
  printArray(PreOrder, preIndex);

  printf("In-order: ");
  printArray(InOrder, inIndex);

  printf("Post-order: ");
  printArray(PostOrder, postIndex);

  stack_traverseTree(p);

  delete(&p, 23);
  delete(&p, 1);
  delete(&p, 3);
  delete(&p, 9);


  stack_traverseTree(p);



}