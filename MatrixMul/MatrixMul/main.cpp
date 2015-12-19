#include <iostream>
#include <conio.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 1
#define N (1<<M)

typedef double datatype;
#define DATATYPE_FORMAT "%4.2g"
typedef datatype mat[N][N];
typedef struct
{
        int ra, rb, ca, cb;
} corners;
// set A[a] = I
void identity(mat A, corners a)
{
    int i, j;
    for (i = a.ra; i < a.rb; i++)
        for (j = a.ca; j < a.cb; j++)
            A[i][j] = (datatype) (i == j);
}
// set A[a] = k
void set(mat A, corners a, datatype k)
{
    int i, j;
    for (i = a.ra; i < a.rb; i++)
        for (j = a.ca; j < a.cb; j++)
            A[i][j] = k;
}
 
// set A[a] = [random(l..h)].
void randk(mat A, corners a, double l, double h)
{
    int i, j;
    for (i = a.ra; i < a.rb; i++)
        for (j = a.ca; j < a.cb; j++)
            A[i][j] = (datatype) (l + (h - l) * (rand() / (double) RAND_MAX));
}
 
// Print A[a]
void print(mat A, corners a, char *name)
{
    int i, j;
    printf("%s = {\n", name);
    for (i = a.ra; i < a.rb; i++)
    {
        for (j = a.ca; j < a.cb; j++)
            printf(DATATYPE_FORMAT ", ", A[i][j]);
        printf("\n");
    }
    printf("}\n");
}
// C[c] = A[a] + B[b]
void add(mat A, mat B, mat C, corners a, corners b, corners c)
{
    int rd = a.rb - a.ra;
    int cd = a.cb - a.ca;
    int i, j;
    for (i = 0; i < rd; i++)
    {
        for (j = 0; j < cd; j++)
        {
            C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] + B[i + b.ra][j
                    + b.ca];
        }
    }
}
 
// C[c] = A[a] - B[b]
void sub(mat A, mat B, mat C, corners a, corners b, corners c)
{
    int rd = a.rb - a.ra;
    int cd = a.cb - a.ca;
    int i, j;
    for (i = 0; i < rd; i++)
    {
        for (j = 0; j < cd; j++)
        {
            C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] - B[i + b.ra][j
                    + b.ca];
        }
    }
}
// Return 1/4 of the matrix: top/bottom , left/right.
void find_corner(corners a, int i, int j, corners *b)
{
    int rm = a.ra + (a.rb - a.ra) / 2;
    int cm = a.ca + (a.cb - a.ca) / 2;
    *b = a;
    if (i == 0)
        b->rb = rm; // top rows
    else
        b->ra = rm; // bot rows
    if (j == 0)
        b->cb = cm; // left cols
    else
        b->ca = cm; // right cols
}
int main()
{
     mat A, B, C;
    corners ai = { 0, N, 0, N };
    corners bi = { 0, N, 0, N };
    corners ci = { 0, N, 0, N };
    srand(time(0));
    randk(A, ai, 0, 3);
    randk(B, bi, 0, 3);
    print(A, ai, "A");
    print(B, bi, "B");
    set(C, ci, 0);
    //mul(A, B, C, ai, bi, ci);
    //print(C, ci, "C");
	getch();
    return 0;
}