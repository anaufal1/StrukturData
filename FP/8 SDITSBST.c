#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tree
{    char v[18];
    int len, index, plus_l, plus_r;
    struct _tree *l, *r;
} Tree;

void Ins(Tree **t, char *val, int val_len, int indeks)
{    if(!(*t))
    {    *t = (Tree*)malloc(sizeof(Tree));

        strcpy((*t)->v, val);

        (*t)->len = val_len;
        (*t)->index = indeks;

        (*t)->plus_l = (*t)->plus_r = 0;
        (*t)->l = (*t)->r = NULL;
    }
    else if(((*t)->len > val_len) || (((*t)->len == val_len) && (strcmp((*t)->v, val) > 0)))
    {    if((*t)->r) Ins(&(*t)->r, val, val_len, 1);
        else
        {    Ins(&(*t)->r, val, val_len, (*t)->index + 1);
            (*t)->plus_r = 0;
        }
    }
    else
    {    (*t)->index += 1;
        (*t)->plus_r += 1;

        if((*t)->l) Ins(&(*t)->l, val, val_len, 1);
        else
        {    Ins(&(*t)->l, val, val_len, (*t)->index - 1);
            (*t)->plus_l = 0;
        }
    }
}

int Find(Tree **t, char *val, int val_len)
{    if(*t)
    {    if(strcmp((*t)->v, val) == 0)
        {    printf("%d\n", (*t)->index);
            return 1;
        }

        else if(((*t)->len > val_len) || (((*t)->len == val_len) && (strcmp((*t)->v, val) > 0)))
        {    if((*t)->plus_r)
            {    if((*t)->r)
                {    int t_plus_r = (*t)->plus_r;

                    (*t)->r->index += t_plus_r;
                    (*t)->r->plus_l += t_plus_r;
                    (*t)->r->plus_r += t_plus_r;
                }

                (*t)->plus_r = 0;
            }

            return Find(&(*t)->r, val, val_len);
        }

        else
        {    if((*t)->plus_l)
            {    if((*t)->l)
                {    int t_plus_l = (*t)->plus_l;

                    (*t)->l->index += t_plus_l;
                    (*t)->l->plus_l += t_plus_l;
                    (*t)->l->plus_r += t_plus_l;
                }

                (*t)->plus_l = 0;
            }

            return Find(&(*t)->l, val, val_len);
        }
    }
    else return 0;
}

int main()
{    int T, cmd, len;
    scanf("%d", &T);

    Tree *t = NULL;
    char val[18];

    while(T--)
    {    scanf("%d %s", &cmd, val);
        len = strlen(val);

        if(cmd == 1) Ins(&t, val, len, 1);
        else if(!Find(&t, val, len)) printf("Data tidak ada\n");
    }

    return 0;
}
