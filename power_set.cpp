#include <iostream>
using namespace std;

void subsets(int arr[],int n,int subset[],int subsetsize,int index){
    if(index==n){
        for(int i=0;i<subsetsize;i++){
            cout<<subset[i];
        }
        cout<<endl;
        return; //////////
    }
    subsets(arr,n,subset,subsetsize,index+1);
    subset[subsetsize]=arr[index]; /////
    subsets(arr,n,subset,subsetsize+1,index+1);

}

int main(){
    int n;
    cout<<"enter number the elements: ";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"enter element: ";
        cin>>arr[i];
    }
    int *subset=new int[n];
    subsets(arr,n,subset,0,0);
    
}