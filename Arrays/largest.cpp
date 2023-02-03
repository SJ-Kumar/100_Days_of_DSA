#include<iostream>
using namespace std;
int main()
{
        int large, arr[100],n;
        cin>>n;
        cout<<"\n Enter Array Elements : \n";
        for(int i=0; i<n; i++)
        {
                cin>>arr[i];
        }
        cout<<"\n Searching for Largest Number ...\n\n";
        large=arr[0];
        for(i=0; i<n; i++)
        {
                if(large<arr[i])
                {
                        large=arr[i];
                }
        }
        cout<<"Largest Number = "<<large;
        return 0;
}
