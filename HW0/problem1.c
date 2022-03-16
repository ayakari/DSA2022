#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct len_arr
{
    int len;
    int *arr;
};
typedef struct len_arr len_arr;
 
len_arr *GCD(len_arr *a ,len_arr *b);
void MOD(len_arr *a ,len_arr *b);
int MINUS(len_arr *a ,len_arr *b);
void PARR(len_arr *a);
int cmp_ab(len_arr *a , len_arr *b);
int cmp_0(len_arr *a);
//int Getlen(len_arr *a);
 
 
int main()
{
    char *L = malloc(sizeof(char)* 300);
    char *S = malloc(sizeof(char)* 300);
    scanf("%s %s" , L , S);
 
    int Llen = strlen(L) , Slen = strlen(S); 
    if(Llen == Slen)
    {
        if(L[0] < S[0])
        {
            //printf("dick");
            char *temp = L;
            L = S ;
            S = temp;
        }
    }
    if(Llen < Slen)
    {
        char *temp = L;
        L = S ;
        S = temp;
 
        int temp2 = Llen ;
        Llen = Slen;
        Slen = temp2; 
    }
 
 
    len_arr *a = malloc(sizeof(len_arr)), *b = malloc(sizeof(len_arr));
    a -> len = Llen , b -> len = Slen;
    a -> arr = malloc(sizeof(int) * 300);
    a -> arr[a -> len] = -1;
    b -> arr = malloc(sizeof(int) * 300);
    b -> arr[b -> len] = -1;
 
    for(int i = 0 ; i < a->len ; i ++)
        a->arr[a->len - 1 - i] = L[i] - 48;
    for(int i = 0 ; i < b->len ; i ++)
        b->arr[b->len - 1 - i] = S[i] - 48;
 
    /*
    for(int i = 0 ; i < a->len ; i ++)
        printf("%d " , a->arr[a->len - 1 - i]);
    printf("\n");
    for(int i = 0 ; i < b->len ; i ++)
        printf("%d " , b->arr[b->len - 1 - i]);
    */  /*
    printf("a->len = %d , b->len = %d\n" , a->len , b->len);
    printf("cmp_ab = %d \n" , cmp_ab(a , b));
    printf("cmp_0 = %d \n" , cmp_0(b));
    */
 
    //GCD(a,b);
 
    PARR(GCD(a,b));
    return 0;
}
 
void PARR(len_arr *a)
{
    for(int i = 0 ; i < a->len; i ++)
    {
        printf("%d" , a->arr[a->len - 1 - i]);
    }
    printf(" ");
    return;
}
 
int cmp_ab(len_arr *a , len_arr *b)//1 : a > b , 0 : a = b ; -1 a < b
{
    if(a->len < b-> len)
        return -1;
    if(a->len > b->len)
        return 1;
    if(a->len = b->len)
    {
        int last = a->len-1;
        for(int i = last ; i > -1 ; i --)
        {
            if(a->arr[i] > b->arr[i])
                return 1;
            if(a->arr[i] < b->arr[i])
                return -1;
        }
 
        return 0 ;
    }
}
 
len_arr *GCD(len_arr *a , len_arr *b)
{
    if(b->len == 1)
    {
        if(b->arr[0] == 0)
        {
            b->arr[0] = 1;
            return b;
        }
    }
 
    while(cmp_0(b) !=  0)
    {
        //PARR(a);PARR(b);
        MOD(a , b);
        //printf("\n");
        len_arr *temp = a;
        a = b ;
        b = temp;
        if(cmp_ab(a,b) == 0)
            break;
    }
    //PARR(a);PARR(b);
 
    return a;
}
 
int cmp_0(len_arr *a)
{
    if(a -> len == 1 && a->arr[0] == 0)
        return 0;
 
    for(int i = a -> len - 1; i > -1 ; i--)
    {
        if(a->arr[i] > 0){
            return 1;
        }
        else if(a->arr[i] < 0){
            return 0;
        }
    }
}
 
int MINUS(len_arr *a ,len_arr *b)//success : 1 , fail : 0
{
    //printf("in function\n");
    int *aarr = a->arr , *barr = b->arr ;
    if(cmp_ab(a , b) < 0)
        return 0;
 
    for(int i = 0 ; i < b->len ; i++)
    {
        //PARR(a);printf("\n");
        aarr[i] -= barr[i];
    }
    int bor = 0;
    for(int i = 0 ; i < a->len ; i++)
    {
 
        if(bor == 1)
            aarr[i] --;
        if(aarr[i] > -1)
        {
            bor = 0;
        }else{
            aarr[i] += 10;
            bor = 1;
        }
 
    }
 
    /*
    if(aarr[a->len - 1] < 1)
    {   
        PARR(a);printf("\n");
        int in = 0;
        for(int i = a->len - 1; i > -1 ; i--)
        {
            if(aarr[i] > 0)
            {
                a->len = i+1;
                in = 1;
            }
        }
        if(in == 0)
            a->len = 1;
        
    }*/
    for(int i = a->len - 1 ; i > -1 ; i--)
    {
        if(aarr[i] == 0){
            a->len--;
        }else{
            break;
        }
    }
 
    return 1;
}
 
void MOD(len_arr *a ,len_arr *b)
{
    while(cmp_ab(a , b) > 0)
        MINUS(a , b);
 
    return ;
}