/*
Given an array of positive and negative integers, develop a linear algorithm and write a C++ code to check if there 
exist a subarray whose sum is zero is present in it. If such a subarray exist then 
print start and end index of first occurrence. Otherwise print -1 for both start and end index. 
For example, if the array contains seven elements 10, -3, 2,4, -3, 5, 7 then print start index as 2 and end index as 5

Hint: Use maps for keeping track of sums 

Note: If more than one zero sum subarray exist then print the one which has got maximum length

Input Format

First line contains the number of elements in the array, n

Next line contains the elements separated by a space

Output Format

Either print start index and end index of subarray whose sum becomes 0 or print -1 if no such subarray exist

*/

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map <int,int> map;
    int sum=0,start=-1,end=-1,max_len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            max_len=i+1;start=0;end=i;
            break;
        }
        if(map.find(sum)!=map.end()){
            int len=i-map[sum];
            if(len>max_len){
                max_len=len;
                start=map[sum]+1;
                end=i;
            }
        }
        else{
            map[sum]=i;
        }
    }
    if(start!=-1 && end!=-1)
    {
        cout<<start+1<<" "<<end+1;
    }
    else{
        cout<<"-1";
    }
    return 0;
}
