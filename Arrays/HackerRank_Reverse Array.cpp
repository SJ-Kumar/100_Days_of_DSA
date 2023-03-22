#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;
    cin>>num;
    int arr[num];
    int i,j;
    for(i=0;i<num;i++){
        cin>>arr[i];
    }
    for ( i = 0, j = num - 1; i < num/2; i++, j--)  
    {     
        int temp = arr[i];  
        arr[i] = arr[j];  
        arr[j] = temp;  
    } 
    for(i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
