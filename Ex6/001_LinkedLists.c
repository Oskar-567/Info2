#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions already implemented */
struct month *init_months(struct month *head);
void free_months(struct month *head);

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    /* Task 2.1 */

    struct month *pointer = head;
    while (pointer != NULL)
    {
       printf("%s (%d) \n", pointer->month_name, pointer->month_number);
       pointer = pointer->next;
    }
}

struct month *get_previous_month(struct month *head, struct month *a){
    /* Task 2.2 */
    if (head == NULL || a == NULL) {return NULL;}
    else if (head == a) {return NULL;}

    struct month *p = head;

    while (p->next != a) {p = p->next;}
    return p;
    }


struct month *swap_month(struct month *head, struct month *a, struct month *b) {
    /* Task 2.3 */

    if (a == NULL || b == NULL || a == b) return head;

    struct month *prevA = get_previous_month(head, a);
    struct month *prevB = get_previous_month(head, b);

    // Falls a und b direkt benachbart sind
    if (a->next == b) {
        if (prevA != NULL) prevA->next = b;
        a->next = b->next;
        b->next = a;
        if (head == a) head = b;
        return head;
    }

    /*						// Falls b head ist. Aber durch Aufgabenstellung wird dies ausgeschlossen.
    if (b->next == a) {
        if (prevB != NULL) prevB->next = a;
        b->next = a->next;
        a->next = b;
        if (head == b) head = a;
        return head;
    }
	*/

    // Falls einer von beiden Head ist
    if (prevA != NULL) prevA->next = b;
    if (prevB != NULL) prevB->next = a;

    struct month *temp = a->next;
    a->next = b->next;
    b->next = temp;

    if (head == a) head = b;
    else if (head == b) head = a;

    return head;
}


struct month *selection_sort(struct month *head) {
    /* Task2.4 */
    struct month *i = head;
    struct month *j;
    struct month *current_min;

    while (i->next != NULL)
    {
      current_min = i;
      j = i->next;
      //print_months(head);
      while (j != NULL)
      {
        if (current_min->month_number > j->month_number)
        {
          current_min = j;
        }
        j = j->next;
      }
      head = swap_month(head, i, current_min);
      i = current_min->next;
    }
    return head;
}

struct month *searchformonth(struct month *head, int num)
{
  struct month *temp = head;
  while(temp->month_number != num)
  {
    temp = temp->next;
  }
  return temp;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);


    /* Print the linked list as it is after initialization */
    print_months(head);

    //Print the previous month
    int given_month_number = 4;
    struct month *searchedmonth = searchformonth(head, given_month_number);
    struct month *prev = get_previous_month(head, searchedmonth);
    if (prev != NULL) {printf("Vorheriger Monat von %d ist %s.\n", given_month_number, prev->month_name);}
    if (prev == NULL) {printf("Kein vorheriger Monat gefunden.\n");}

    //Swap Months
    int zahl1; int zahl2;
    printf("Gebe die zu tauschenden Monate in Zahlen ein (Monat A muss vor Monat B kommen)\n");
    printf("Monat A: ");
    scanf("%d", &zahl1);
    printf("Monat B: ");
    scanf("%d", &zahl2);

    struct month *a = searchformonth(head, zahl1);
    struct month *b = searchformonth(head, zahl2);

    if (a != NULL && b != NULL) {
        head = swap_month(head, a, b);
        printf("\nNach dem Tauschen:\n");
        print_months(head);
    } else {
        printf("Mindestens einer der Monate wurde nicht gefunden.\n");
    }



    /* Task 2.4 */
    printf("\nSelection Sort\n");
    head = selection_sort(head);
    print_months(head);

    /* Cleanup */
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
