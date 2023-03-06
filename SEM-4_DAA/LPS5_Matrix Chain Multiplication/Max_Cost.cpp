/*
Modify the algorithm developed in problem 4 (matrix chain multiplication problem) to find the way to parenthesize that will have maximum number of multiplications. Print the matrices with parenthesis that will have maximum number of multiplications as well. For example given three matrices and dimension as follows:

4
10 100 5 50

The code must print the m table as 
5000 75000 
25000 

S table as
1 1 
2 

Maximum cost is
75000

Paraenthesization of matrices is 
(A1(A2A3))

Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the maximum cost

Print the parenthesization that will lead to maximum cost

*/




#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int m[100][100];
int s[100][100];
int mcm(int p[],int i,int j){
    if(m[i][j]!=0){
        return m[i][j];
    }
    if(i==j){
        return 0;
    }
    m[i][j]=INT_MIN;
    for(int k=i;k<j;k++){
        int h=max(m[i][j],mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j]);
        if(h>m[i][j]){
            s[i-1][j-1]=k;
            m[i][j]=h;
        }
    }
    return m[i][j];
}
void printer(vector<vector<int>>s, int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printer(s,i,s[i-1][j-1]);
        printer(s,s[i-1][j-1]+1,j);
        cout<<")";
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=mcm(a,1,n-1);
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>>s1;
    for(int i=0;i<n-1;i++){
        vector<int>s2;
        for(int j=0;j<n-1;j++){
            s2.push_back(0);
        }
        s1.push_back(s2);
    }
    for(int i=0;i<n-2;i++){
        vector<int>s2;
        for(int j=i+1;j<n-1;j++){
            cout<<s[i][j]<<" ";
            s1[i][j]=s[i][j];
        }
        cout<<endl;
    }
    cout<<c<<endl;
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1;j++){
    //         cout<<s1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    printer(s1,1,n-1);
}
