#include <iostream>
using namespace std;

int main(){
    int n;int arr[100],i,j;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n Array Elements : \n\n";
    for(i=0; i<n; i++){
        cout<<arr[i]<<" "<<endl;
    }
    j=i-1;
    i=0;
    if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
