#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;
int main()
{
    int raz1,raz2,dva1,dva2;
    int i,j,k;
    cout<<"Vvedite [x][y] pervoi matricy:"; cin>>raz1>>raz2;
    cout<<"Vvedite [x][y] vtoroy matricy:"; cin>>dva1>>dva2;
    int **matrix1 = new int*[raz1*2];   
    for(i=1; i<=raz1;i++) 
    { 
    matrix1[i]=new int[raz2*2]; 
    } 
    
    int **matrix2 = new int*[dva1*2]; 
    for(i=1; i<=dva1;i++) 
    { 
    matrix2[i]=new int[dva2*2]; 
    }
    
    int *rowFactor = new int[dva2*2];
    int *columnFactor = new int[dva2*2];
 
    int **R = new int*[raz1*2];
    for (i=1; i<=dva1; i++)
    {
        R[i]=new int[dva1*2];
    }
    
    for (i=1; i<=raz1; i++)
    {
    for (j=1; j<=raz2; j++)
    {
        cout<<"Matrix1["<<i<<"]["<<j<<"]="; cin>>matrix1[i][j];
    }
    }
   
    for (i=1; i<=dva1; i++)
    {
    for (j=1; j<=dva2; j++)
    {
        cout<<"Matrix2["<<i<<"]["<<j<<"]="; cin>>matrix2[i][j];
    }
    }
   
    dva2=raz2/2;
    for (i = 1; i<=raz1; i++){
    rowFactor[i] = matrix1[i][1]*matrix1[i][2];
    for (j = 1; j<=dva2; j++){
    rowFactor[i] = rowFactor[i] + matrix1[i][2*j-1] * matrix1[i][2*j];
    }
	}
    for (i = 1; i<=dva1; i++){
    columnFactor[i] = matrix2[1][i]*matrix2[2][i];
    for (j = 1; j<=dva2; j++){
    columnFactor[i] = columnFactor[i] + matrix2[2*j-1][i] * matrix2[2*j][i];
    }
	}
   
   for (i=1; i<=raz1; i++)
    {
        for (j=1; j<=dva1; j++)
        {
        R[i][j]=-rowFactor[i]-columnFactor[j];
            for (k=1; k<=dva2; k++)
            {
                R[i][j]=R[i][j]+(matrix1[i][2*k-1]+matrix2[2*k][j])*(matrix1[i][2*k]+matrix2[2*k-1][j]);
            }
        }
    }
    if (2*(raz2/2)==raz2/2) { 
    for (i=1; i<=raz1; i++)
    {
        for (j=1; j<=dva1; j++)
        {
            R[i][j]=R[i][j]+matrix1[i][raz2]*matrix2[raz2][j];
        }
    }
    }
    
    for (i=1; i<=raz1; i++)
    {
        for (j=1; j<=dva1; j++)
        {
            cout<<R[i][j]<<" ";
        }
        cout<<endl;
    }
	getch();
}