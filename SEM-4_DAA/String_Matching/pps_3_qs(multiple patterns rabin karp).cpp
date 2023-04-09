/*
Question

Given a text T[1, ..., n] of length n and k Patterns P1[1, ..., m], P2[1, ..., m],
..., Pk[1, ..., m], modify the given below c++ code for Rabin-Karp algorithm to compute the occurence of any one of the patterns in T

Algorithm

Define a function valueOf(char ch) which takes a character ch as input and returns its numerical value.
Define a function check_characters(string T, string P, int s) which takes a string T, a pattern string P, and an integer s as input, and checks if the pattern string P occurs in string T starting from index s. If it does, the function returns s, else it returns -1.
Define a function rabin_karp_matcher(string T, string P[], int k, int d, int q) which takes a string T, an array of pattern strings P, the number of patterns k, a base number d, and a prime number q as input. The function performs the following steps:
Initialize the length of the text string n, the length of the current pattern string m, the hash value of the current pattern p, the hash value of the current window t0, the variable h which represents the highest power of d that is less than q, and the loop index i.
For each pattern string P[j] in the array of pattern strings P:
Set the current pattern string to P[j].
Set m to the length of the current pattern string.
Compute the hash value p of the current pattern string using the formula (d^m-1) % q.
Compute the hash value t0 of the first window of the text string T of length m using the formula (d^m-1) % q.
For each window of the text string T of length m:
If the hash value of the current window t0 is equal to the hash value of the current pattern p:
Call the function check_characters(T,current_pattern,s) with the text string T, the current pattern string, and the starting index s of the current window as input.
If the function returns a valid index, print the pattern number j+1 and the index where it occurs in the text string T.
If s is less than n-m, update the hash value t0 of the next window of the text string T by subtracting the contribution of the leftmost character and adding the contribution of the rightmost character using the formula (d*(t0-valueOf(T[s])*h)+valueOf(T[s+m]))%q.
In the main function, take input the text string T, the number of patterns k, an array of pattern strings P, the base number d, and the prime number q.
Call the function rabin_karp_matcher(T,P,k,d,q) with the input values.

*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int valueOf(char ch)
{
    return (ch-'0');
}

int check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i])
            return -1;
    }
    return s;
}

void rabin_karp_matcher(string T, string P[], int k, int d, int q)
{
    int n, m, h, p, t0, i, s, j;
    n = T.length();
    h = (int)pow(d,k-1)%q;
    for(j=0; j<k; j++)
    {
        string current_pattern = P[j];
        m = current_pattern.length();
        p = 0;
        t0 = 0;
        for(i=0;i<m;i++)
        {
            p = (d*p + valueOf(current_pattern[i]))%q;
            t0 = (d*t0 + valueOf(T[i]))%q;
        }
        for(s=0;s<=n-m;s++)
        {
            if(p==t0)
            {
                int index = check_characters(T,current_pattern,s);
                if(index!=-1)
                {
                    cout<<"Pattern "<<j+1<<" occurs at index "<<index<<endl;
                }
            }
            if(s<n-m)
                t0 = (d*(t0-valueOf(T[s])*h)+valueOf(T[s+m]))%q;
        }
    }
}

int main()
{
    string T, P[100];
    int d,q,k;
    cout<<"Enter the text: ";
    getline(cin,T);
    cout<<"Enter the number of patterns: ";
    cin>>k;
    cout<<"Enter the patterns: ";
    for(int i=0;i<k;i++)
    {
        cin>>P[i];
    }
    cout<<"Enter base and prime number: ";
    cin>>d>>q;
    rabin_karp_matcher(T,P,k,d,q);
    return 0;
}
