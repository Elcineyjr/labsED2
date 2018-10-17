#include <stdio.h>
#include <stdlib.h>
#include "BQ.h"

typedef struct node {
    Item key;
    struct node *l, *r;
} Node;

#define MAX_SIZE 20 // lg N = 20 ==> N = 1,048,576

struct bq {
    Node* bq[MAX_SIZE];
};

static Node* Node_create(Item v) {
    Node *n = malloc(sizeof *n);
    n->key = v;
    n->l = n->r = NULL;
    return n;
}

static void Node_destroy(Node *n) {
    if (n == NULL) return;
    Node_destroy(n->l);
    Node_destroy(n->r);
    free(n);
}

BQ* BQ_create() {
    BQ *pq = malloc(sizeof *pq);
    for (int i = 0; i < MAX_SIZE; i++) {
        pq->bq[i] = NULL;
    }
    return pq;
}

void BQ_destroy(BQ* pq) {
    if (pq == NULL) return;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (pq->bq[i] == NULL) continue;
        Node_destroy(pq->bq[i]);
    }
    free(pq);
}

static void Node_print(Node *n) {
    if (n == NULL) return;
    printf("%d ", n->key);
    Node_print(n->l);
    Node_print(n->r);
}

/*static void Node_print(Node *n) {
    printf(" / (%d) <- %d -> (%d)", n->l != NULL ? n->l->key : -1,
                                   n->key,
                                   n->r != NULL ? n->r->key : -1 );
    if (n->l != NULL) Node_print(n->l);
    if (n->r != NULL) Node_print(n->r);
}*/

void BQ_print(BQ* pq) {
    printf("BQ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (pq->bq[i] == NULL) continue;
        printf("| 2^%d: ", i);
        Node_print(pq->bq[i]);
    }
    printf("\n");
}

Node* pair(Node *p, Node *q) {
    if (less(p->key, q->key)) {
        p->r = q->l;
        q->l = p;
        return q;
    } else {
        q->r = p->l;
        p->l = q;
        return p;
    }
}

void BQ_insert(BQ* pq, Item v) {
    Node *n = Node_create(v);
    for (int i = 0; i < MAX_SIZE; i++) {
        if (pq->bq[i] == NULL) { pq->bq[i] = n; break; }
        n = pair(n, pq->bq[i]);
        pq->bq[i] = NULL;
    }
}

#define test(C, B, A) (4*(C) + 2*(B) + 1*(A))
static void join(Node* a[], Node* b[]) {
    Node *c = NULL;
    for (int i = 0; i < MAX_SIZE; i++)
        switch(test(c != NULL, b[i] != NULL, a[i] != NULL)) {
            case 2: a[i] = b[i]; break;
            case 3: c = pair(a[i], b[i]); a[i] = NULL; break;
            case 4: a[i] = c; c = NULL; break;
            case 5: c = pair(c, a[i]); a[i] = NULL; break;
            case 6:
            case 7: c = pair(c, b[i]); break;               }
}

void BQ_join(BQ *a, BQ *b) {
    join(a->bq, b->bq);
    free(b); // Don't call BQ_destroy(b) here because we have alising on 'a'!
}

Item BQ_delmax(BQ* pq) {
    int max = -1; Item v;
    for (int i = 0; i < MAX_SIZE; i++) // Search max among roots
        if ( pq->bq[i] != NULL &&      // of power-of-2 heaps.
             (max == -1 || less(v, pq->bq[i]->key)) )
              { max = i; v = pq->bq[max]->key; }
    Node *x = pq->bq[max]->l;
    BQ *temp = BQ_create();
    for (int i = max; i > 0; i--) // Split heap with max.
      { temp->bq[i-1] = x; x = x->r; temp->bq[i-1]->r = NULL; }
    free(pq->bq[max]);  pq->bq[max] = NULL;
    BQ_join(pq, temp);
    return v;
}
