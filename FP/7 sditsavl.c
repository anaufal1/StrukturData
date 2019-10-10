#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int v, h, idx, pl, pr;
    struct _node *l, *r;
} Node;

typedef struct {
    Node *r;
} Tree;

int height(Node *n) {
    return n? n->h: 0;
}

int max(int h1, int h2) {
    return h1 > h2? h1: h2;
}

void fixheight(Node *n) {
    if(n) n->h = max(height(n->l), height(n->r)) + 1;
}

Node *RR(Node *n) {
    Node *a = n->l;

    n->l = a->r;
    a->r = n;

    fixheight(n);
    fixheight(a);

    a->idx += n->pl;
    a->pl += n->pl;
    n->pl += a->pr;
    a->pr = 0;

    return a;
}

Node *RL(Node *n) {
    Node *a = n->r;

    n->r = a->l;
    a->l = n;

    fixheight(n);
    fixheight(a);

    a->idx += n->pr;
    a->pr += n->pr;
    n->pr += a->pl;
    a->pl = 0;

    return a;
}

int GetBal(Node *n) {
    return n? height(n->l) - height(n->r): 0;
}

Node *Bal(Node *n) {
    fixheight(n);
    int bl = GetBal(n);

    if(bl < -1) {
        if(GetBal(n->r) > 1) n->r = RR(n->r);
        return RL(n);
    } else if(bl > 1) {
        if(GetBal(n->l) < -1) n->l = RL(n->l);
        return RR(n);
    }

    return n;
}

Node *CreateNode(int val, int idx) {
    Node *tmp = (Node*)malloc(sizeof(Node));

    tmp->v = val;
    tmp->idx = idx;
    tmp->h = 1;
    tmp->pl = tmp->pr = 0;
    tmp->l = tmp->r = NULL;

    return tmp;
}

Node *Add(Node *n, int val, int idx) {
    if(!n) return CreateNode(val, idx);
    else if(val < n->v) {
        n->idx += 1;
        n->pr += 1;

        if(n->l) n->l = Add(n->l, val, idx);
        else {
            n->l = Add(n->l, val, n->idx - 1);
            n->pl = 0;
        }
    } else {
        if(n->r) n->r = Add(n->r, val, idx);
        else {
            n->r = Add(n->r, val, n->idx + 1);
            n->pr = 0;
        }
    }

    return Bal(n);
}

void Find(Node *n, int val) {
    Node *i = n;

    while(i)
        if(val == i->v) {
            printf("%d\n", i->idx);
            return;
        } else if(val < i->v) {
            if(i->pl) {
                if(i->l) {
                    i->l->idx += i->pl;
                    i->l->pl += i->pl;
                    i->l->pr += i->pl;
                }
                i->pl = 0;
            }

            i = i->l;
        } else {
            if(i->pr) {
                if(i->r) {
                    i->r->idx += i->pr;
                    i->r->pl += i->pr;
                    i->r->pr += i->pr;
                }
                i->pr = 0;
            }

            i = i->r;
        }

    printf("Data tidak ada\n");
}

int main() {
    Tree *t = (Tree*)malloc(sizeof(Tree));
    t->r = NULL;

    int T, cmd, n;
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &cmd, &n);
        if(cmd == 1) t->r = Add(t->r, n, 1);
        else Find(t->r, n);
    }
}
