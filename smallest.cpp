#include <iostream>
using namespace std;

int main(){
    int n;int arr[100],small;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    small=arr[0];
    for(int i=0;i<n;i++){
        if(small>arr[i]){
            small=arr[i];
        }
    }
    cout<<"The smallest element is :"<<small;
    return 0;
}
