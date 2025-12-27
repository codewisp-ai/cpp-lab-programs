#include <iostream>
using namespace std;
int **getminor(int **mat,int n,int col){
    int **minor=new int*[n-1];
    for(int i=0;i<n-1;i++){
        minor[i]=new int[n-1];
    }
    for(int i=1;i<n;i++){
        int mcol=0;
        for(int j=0;j<n;j++){
            if(j==col){continue;}
            minor[i-1][mcol]=mat[i][j];
            mcol++;
        }
    }
    return minor;

}
int determinant(int **mat, int n){
   if(n==1){
    return mat[0][0];
   }
   if(n==2){
    return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
   }
   int det=0;
   for(int i=0;i<n;i++){
        int sign=(i%2==0)?1:-1;
        int **minor=getminor(mat,n,i);
        det+=sign*mat[0][i]*determinant(minor,n-1);
   
    for (int j = 0; j < n - 1; j++)
            delete[] minor[j];
        delete[] minor;
   }
   return det;
}

int main(){
    int n;
    cout<<"ENTER THE ORDER OF MATIRX : "<<endl;
    cin>>n;
    int **mat=new int*[n];
    for(int i=0;i<n;i++){
        mat[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    cout<<determinant(mat ,n);
    for(int i=0;i<n;i++){
        delete [] mat[i];
    }
    delete []mat;

    return 0;
}