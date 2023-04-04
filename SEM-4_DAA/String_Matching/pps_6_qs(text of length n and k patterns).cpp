/*
Question

Given j texts T1[1, ..., n], T2[1, ..., n],... Tj [1, ..., n], of length n and k Patterns P1[1, ..., m], P2[1, ..., m], ..., Pk[1, ..., m], 
modify the given below Rabin-Karp c++ code to compute the occurrence of all the valid shifts of all the patterns in all the texts.

Algorithm

Start by taking inputs for the number of texts j, number of patterns k, base d and prime number q.

Create two arrays of strings T and P to store the j texts and k patterns, respectively.

Take inputs for all the texts and patterns and store them in the respective arrays.

For each text T[a] and each pattern P[b], call the Rabin-Karp matcher function with the text T[a], pattern P[b], base d and prime number q as arguments.

In the Rabin-Karp matcher function, calculate the length of the text n and the length of the pattern m.

Calculate the hash value of the pattern P[b] using the given formula and store it in variable p.

Calculate the hash value of the first m characters of text T[a] using the same formula and store it in variable t0.

Calculate the value of h using the formula (d^(m-1))%q.

For each valid shift s, i.e., from -1 to n-m, compare the hash value of pattern P[b] with the hash value of the current substring of text T[a] of length m starting from position s+1.

If the hash values are equal, check if the characters of the substring and pattern are also equal using the check_characters function.

If they are equal, print that the pattern P[b] occurs at shift s+1 in text T[a].

Finally, update the hash value of the next substring of text T[a] using the given formula.

Repeat steps 9 to 12 until all valid shifts of text T[a] have been checked.

Repeat steps 4 to 13 for all texts T and patterns P to find all occurrences of all valid shifts of all patterns in all texts.

*/
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int valueOf(char ch)
{
    return (ch-'0');
}

bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i,s;
    n = T.length();
    m = P.length();
    h = (int)pow(d,m-1)%q;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q;
        t0 = (d*t0 + valueOf(T[i]))%q;
    }
    for(s=-1;s<n-m;s++)
    {
        if(p==t0)
        {
            if (check_characters(T,P,s))
                cout<<"Pattern "<<P<<" occurs at shift "<<s+1<<" in text "<<T<<endl;
        }
        if(s<n-m)
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q;
    }
}

int main()
{
    string T[j], P[k];
    int d,q;
    cout<<"Enter the number of texts: ";
    cin>>j;
    cout<<"Enter the number of patterns: ";
    cin>>k;
    cout<<"Enter base and prime number: ";
    cin>>d>>q;
    for(int a=0; a<j; a++)
    {
        cout<<"Enter text "<<a+1<<": ";
        cin>>T[a];
    }
    for(int b=0; b<k; b++)
    {
        cout<<"Enter pattern "<<b+1<<": ";
        cin>>P[b];
    }
    for(int a=0; a<j; a++)
    {
        for(int b=0; b<k; b++)
        {
            rabin_karp_matcher(T[a], P[b], d, q);
        }
    }
    return 0;
}
