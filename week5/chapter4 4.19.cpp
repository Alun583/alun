#include<stdio.h>
#include<stdlib.h>

typedef struct AVLTREE
{
    int Element;
    int H;
    struct AVLTREE *Left;
    struct AVLTREE *Right;
    struct AVLTREE *Parent;
}ANODE,*Aptr;

int High(Aptr T)
{
    if(T==NULL)
        return -1;
    else
    return T->H;
}

int Max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

Aptr SingleLeft(Aptr K2)
{
    Aptr K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    if(K2->Left!=NULL)
        K2->Left->Parent = K2;
    K1->Right = K2;
    K2->Parent = K1;
    K2->H = Max(High(K2->Left), High(K2->Right)) + 1;
    K1->H = Max(High(K1->Left), High(K1->Right)) + 1;
    return K1;
}

Aptr SingleRight(Aptr K2)
{
    Aptr K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    if(K2->Right!=NULL)
        K2->Right->Parent = K2;
    K1->Left = K2;
    K2->Parent = K1;
    K2->H = Max(High(K2->Left), High(K2->Right)) + 1;
    K1->H = Max(High(K1->Left), High(K1->Right)) + 1;
    return K1;
}

Aptr DoubleLeft(Aptr K3)
{
    Aptr K1,K2;
    K2 = K3->Left;
    K1 = K2->Right;
    K2->Right = K1->Left;
    if(K2->Right!=NULL)
        K2->Right->Parent = K2;
    K3->Left = K1->Right;
    if(K3->Left!=NULL)
        K3->Left->Parent = K3;
    K1->Left = K2;
    K1->Right = K3;
    K2->Parent = K1;
    K3->Parent = K1;
    K3->H = Max(High(K3->Left), High(K3->Right)) + 1;
    K2->H = Max(High(K2->Left), High(K2->Right)) + 1;
    K1->H = Max(High(K1->Left), High(K1->Right)) + 1;
    return K1;
}

Aptr DoubleRight(Aptr K3)
{
    Aptr K1,K2;
    K2 = K3->Right;
    K1 = K2->Left;
    K2->Left = K1->Right;
    if(K2->Left!=NULL)
        K2->Left->Parent = K2;
    K3->Right = K1->Left;
    if(K3->Right!=NULL)
        K3->Right->Parent = K3;
    K1->Left = K3;
    K1->Right = K2;
    K2->Parent = K1;
    K3->Parent = K1;
    K3->H = Max(High(K3->Left), High(K3->Right)) + 1;
    K2->H = Max(High(K2->Left), High(K2->Right)) + 1;
    K1->H = Max(High(K1->Left), High(K1->Right)) + 1;
    return K1;
}

Aptr Insert(int x, Aptr T)
{
    Aptr TMP, TMP1;
    int flag=0;
    TMP = (Aptr)malloc(sizeof(ANODE));
    TMP->Element = x;
    TMP->H = 0;
    TMP->Left = NULL;
    TMP->Right = NULL;
    TMP->Parent = NULL;
    if(T==NULL)
        return TMP;
    else
    {
        if(x!=T->Element)
        {
            TMP1 = T;
            while((x<TMP1->Element && TMP1->Left!=NULL)||(x>TMP1->Element && TMP1->Right!=NULL))
            {
                if(x<TMP1->Element)
                    TMP1 = TMP1->Left;
                else if(x>TMP1->Element)
                    TMP1 = TMP1->Right;
            }
            if(x<TMP1->Element)
            {
                TMP->Parent = TMP1;
                TMP1->Left = TMP;
                flag = 1;
            }
            else if(x>TMP1->Element)
            {
                TMP->Parent = TMP1;
                TMP1->Right = TMP;
                flag = 1;
            }
            if(flag)
            {
                while(TMP1!=NULL)
                {
                    if((High(TMP1->Left)-High(TMP1->Right)==2)||(High(TMP1->Left)-High(TMP1->Right)==-2))
                    {
                        TMP = TMP1->Parent;
                        if(TMP!=NULL)
                            if(TMP->Left==TMP1)
                            {
                                if(x<TMP1->Element)
                                    if(x<TMP1->Left->Element)
                                        TMP1 = SingleLeft(TMP1);
                                    else
                                        TMP1 = DoubleLeft(TMP1);
                                else
                                    if(x>TMP1->Right->Element)
                                        TMP1 = SingleRight(TMP1);
                                    else
                                        TMP1 = DoubleRight(TMP1);
                                TMP->Left = TMP1;
                            }
                            else
                            {
                                if(x<TMP1->Element)
                                    if(x<TMP1->Left->Element)
                                        TMP1 = SingleLeft(TMP1);
                                    else
                                        TMP1 = DoubleLeft(TMP1);
                                else
                                    if(x>TMP1->Right->Element)
                                        TMP1 = SingleRight(TMP1);
                                    else
                                        TMP1 = DoubleRight(TMP1);
                                TMP->Right = TMP1;
                            }
                        else
                            if(x<TMP1->Element)
                                if(x<TMP1->Left->Element)
                                    TMP1 = SingleLeft(TMP1);
                                else
                                    TMP1 = DoubleLeft(TMP1);
                            else
                                if(x>TMP1->Right->Element)
                                    TMP1 = SingleRight(TMP1);
                                else
                                    TMP1 = DoubleRight(TMP1);
                        TMP1->Parent = TMP;
                    }
                    TMP1->H = Max(High(TMP1->Left),High(TMP1->Right)) + 1;
                    if(TMP1->Parent==NULL)
                        T = TMP1;
                    TMP1 = TMP1->Parent;
                }
            }
        }
        return T;
    }
}

void PrintX(Aptr T)
{
    if(T!=NULL)
    {
        PrintX(T->Left);
        PrintX(T->Right);
        printf("%d ",T->Element);
    }
}

void PrintH(Aptr T)
{
    if(T!=NULL)
    {
        PrintH(T->Left);
        PrintH(T->Right);
        printf("%d ",T->H);
    }
}

void PrintD(Aptr T)
{
    if(T!=NULL)
    {
        PrintD(T->Left);
        PrintD(T->Right);
        printf("%d ",High(T->Left)-High(T->Right));
    }
}

int main()
{
    int i,arr[]={2,1,4,5,9,3,6,7};
    Aptr T;
    T = NULL;

    for(i=0;i<8;i++)
    {
        T = Insert(arr[i],T);
        printf("NODE OF AVLTREE:\n");
        PrintX(T);
        printf("\nHEIGHT OF AVLTREE:\n");
        PrintH(T);
        printf("\nDELTH OF AVLTREE:\n");
        PrintD(T);
        printf("\n");
    }
    return 0;
}
