#include<stdio.h>
#include<stdlib.h>

//#define MAX(a, b) ((a > b) ? a : b)
#define max(a, b) (a > b ? a : b)
struct AvlNode;
typedef struct AvlNode *AvlTree;
typedef struct AvlNode *Position;

struct AvlNode {
    int element;
    AvlTree Left;
    AvlTree Right;
    int height;
};

AvlTree MakeEmpty(AvlTree T);
Position Find(int X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int X, AvlTree T);
AvlTree Delete(int X, AvlTree T);
int Retrieve(Position P);

static int Height(Position P)
{
    if (P == NULL) {
        return -1;
    } else {
        return P->height;
    }
}

AvlTree MakeEmpty(AvlTree T)
{
    if (T->Left == NULL && T->Right == NULL) {
        T = NULL;
    } else if (T->Left != NULL) {
        MakeEmpty(T->Left);
    } else {
        MakeEmpty(T->Right);
    }
    return T; 
}

Position Find(int X, AvlTree T)
{
    if (T == NULL || T->element == X) {
        return T;
    } else if (X < T->element && T->Left != NULL) {
        Find(X, T->Left);
    } else if (X > T->element && T->Right != NULL) {
        Find(X, T->Right);
    }
    return T;
}

static Position SingleRetateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    
    K2->height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->height = max(Height(K1->Left), Height(K1->Right)) + 1;
    return K1;
}

static Position SingleRetateWithRight(Position K2)
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;

    K2->height = max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->height = max(Height(K1->Left), Height(K1->Right)) + 1;
    return K1;
}

static Position DoubleRetateWithLeft(Position K3)
{
    K3->Left = SingleRetateWithRight(K3->Left);
    return SingleRetateWithLeft(K3);
}

static Position DoubleRetateWithRight(Position K3)
{
    K3->Right = SingleRetateWithLeft(K3->Right);
    return SingleRetateWithRight(K3);
}

AvlTree Insert(int X, AvlTree T)
{
    if (T == NULL) {
        //printf("  sssss");
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL) {
            printf("Malloc Error!");
        } else {
            T->element = X;
            T->height = 0;
            T->Left = NULL;
            T->Right = NULL;
            //printf("aaaa");
        }

    } else if (X < T->element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->element) {
                T = SingleRetateWithLeft(T);
            } else {
                T = DoubleRetateWithLeft(T);
            }
        }
    } else if (X > T->element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->element) {
                T = SingleRetateWithRight(T);
            } else {
                T = DoubleRetateWithRight(T);
            }
        }
    }

    T->height = max(Height(T->Left), Height(T->Right)) + 1;
    //printf("gggg");
    return T;
}

Position FindMin(AvlTree T)
{
    Position tmp = T;
    if (tmp == NULL) {
        return NULL;
    } else {
        while (tmp->Left != NULL) {
            tmp = tmp->Left;
        }
        return tmp;
    }
}

AvlTree Delete(int X, AvlTree T)
{
    if (T == NULL) {
        return NULL;
    } else if (X < T->element) {
        T->Left = Delete(X, T->Left);
    } else if (X > T->element) {
        T->Right = Delete(X, T->Right);
    } else {
        if (T->Left == NULL || T->Right == NULL) {
            Position tmp = T->Left ? T->Left : T->Right;
            if (tmp == NULL) {
                tmp = T;
                T = NULL;
            } else {
                T->element = tmp->element;
                T->Left = NULL;
                T->Right = NULL;
            }
            free(tmp);
        } else {
            Position tmp = FindMin(T->Right);
            //printf("%d\n", tmp->element);
            T->element = tmp->element;
            //printf("%d\n", T->element);
            T->Right = Delete(tmp->element, T->Right);
            //printf("error");
        }
    }

    if (T == NULL) {
        return T;
    }
        
    T->height = max(Height(T->Left), Height(T->Right)) + 1;

    if (Height(T->Left) - Height(T->Right) == 2) {
            if (X > T->Left->element) {
                T = SingleRetateWithLeft(T);
            } else {
                T = DoubleRetateWithLeft(T);
            }
    }
    if (Height(T->Right) - Height(T->Left) == 2) {
            if (X < T->Right->element) {
                T = SingleRetateWithRight(T);
            } else {
                T = DoubleRetateWithRight(T);
            }
    }
    
    return T;
}

void DisPreOrder(AvlTree T)
{
    if (T != NULL) {
        printf("%d ", T->element);
        DisPreOrder(T->Left);
        DisPreOrder(T->Right);
    }
    //printf("\n");
}

int main()
{
    AvlTree T = NULL;

    // T = (AvlTree)malloc(sizeof(struct AvlNode));
    // if (T == NULL) {
    //     printf("error");
    // } else {
    //     T->element = 5;
    //     T->height = 0;
    //     T->Left = NULL;
    //     T->Right = NULL;
    // }
    T = Insert(9, T);
    //printf("%d ", T->element);
    T = Insert(5, T);
    T = Insert(10, T);
    T = Insert(0, T);
    T = Insert(6, T);
    T = Insert(11, T);
    T = Insert(-1, T);
    T = Insert(1, T);
    T = Insert(2, T);
    DisPreOrder(T);
    printf("\n");
    T = Delete(10, T);
    DisPreOrder(T);
    printf("\n");
    // Position tmp = FindMin(T->Right);
    // printf("%d\n", tmp->element);
    T = Delete(1, T);
    DisPreOrder(T);
    printf("\n");
    return 0;
}