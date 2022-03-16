#include <stdio.h>
#include <stdlib.h>

struct matrix{
    int **cor;//[x][y]↓→
    int N;
    int M;
};
typedef struct matrix matrix;

struct clues{
    int **row;
    int **col;
    int *clu_num_row;
    int *clu_num_col;
};
typedef struct clues clues;

void scan_clues(matrix *a , clues *b);
void matrix_ini(matrix *a );
void print_matrix(matrix *a);


int main()
{
    matrix mat1;//N for row , M for col
    scanf("%d %d" , &mat1.N , &mat1.M);
    matrix_ini(&mat1);
    clues clu1;
    //scan_clues(&mat1 , &clu1);
    
    print_matrix(&mat1);
    return 0;
}

void matrix_ini(matrix *a)
{
    int N = a->N , M = a->M;
    a->cor = malloc(sizeof(int*) * N);
    for(int i = 0 ; i < N ; i++)
    {
        a->cor[i] = malloc(sizeof(int*) * M) ;
        for(int j = 0 ; j < M ; j++)
        {
            a->cor[i][j] = 1;
        }
    }
    return;
}

void print_matrix(matrix *a)
{
    int N = a->N , M = a->M;
    for(int i = 0 ; i < 5 ; i ++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            switch(a->cor[i][j])
            {
                case 1:
                printf("o");
                break;

                case -1:
                printf("_");
                break;

                default :
                printf("\nerror");
                return;
            }
        }
        printf("\n");
    }

    return;
    

}

void scan_clues(matrix *a , clues *b)
{
    int N = a->N , M = a->M;
    b->row = malloc(sizeof(int*) * N) , b-> col= malloc(sizeof(int*) * M); 
    b->clu_num_row = malloc(sizeof(int) * N), b->clu_num_col = malloc(sizeof(int) * M);
    for(int i = 0 ; i < N ; i++)
    {
        scanf("%d" , &b->clu_num_row[i]);
        b->row[i] = malloc(sizeof(int)*b->clu_num_row[i]);
        for(int j = 0 ; j < b->clu_num_row[i] ; j++)
        {
            scanf("%d " , &b->row[i][j]);
        }
    }
    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d" , &b->clu_num_col[i]);
        b->col[i] = malloc(sizeof(int)*b->clu_num_col[i]);
        for(int j = 0 ; j < b->clu_num_col[i] ; j++)
        {
            scanf("%d " , &b->col[i][j]);
        }
    }
    
    return;

}
