/*
In matrix chain multiplication problem, given the number of matrices to be multiplied, write a C++ program to find the number of ways it may be parenthesized. For example, when there are three matrices A1, A2 and A3 there are two ways to parenthesize them. (A1(A2A3)) and ((A1A2)A3). If there are four matrices A1, A2, A3 and A4 then there are five ways to parenthesize as shown (A1(A2(A3A4))), (A1((A2A3)A4)), ((A1,A2)(A3A4)), ((A1(A2A3))A4), (((A1A2)A3)A4).

Input Format

First line contains the number of matrices in the chain, n

Output Format

Print the possible number of parenthesization

*/

#include<iostream>
using namespace std;
int count(int n){
    if(n<=1){
        return 1;
    }
    int z=0;
    for(int i=1;i<n;i++){
        z=z+count(i)*count(n-i);
    }
    return z;
}
int main(){
    int n;
    cin>>n;
    int y=count(n);
    cout<<y;
}
