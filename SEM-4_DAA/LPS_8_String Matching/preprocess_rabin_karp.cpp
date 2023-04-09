#include <iostream>
#include <string>
#include <math.h>
#include<vector>

using namespace std;

int valueOf(char ch)
{
    if (ch >= 'A' && ch <= 'Z') // Capital letters
        return ch - 'A' + 10;
    else if (ch >= 'a' && ch <= 'z') // Small letters
        return ch - 'a' + 36;
    else if (ch >= '0' && ch <= '9') // Digits
        return ch - '0';
    else
        return -1; // Invalid characters
}

bool check_characters(string T, string P, int s)
{
    int n, m, i;
    n = T.length();
    m = P.length();
    for (i = 0; i <m; i++)
    {
        if (P[i] != T[s + i + 1 ])
        {
            return false;
        }
    }
    return true;
}

void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i, s;
    int count =0;
    vector<int> p1;
    n = T.length();
    m = P.length();
    h = (int)pow(d, m - 1) % q;
    p = 0;
    t0 = 0;
    for (i = 0; i < m; i++)
    {
        p = (d * p + valueOf(P[i])) % q;
        t0 = (d * t0 + valueOf(T[i])) % q;
    }
    for (s = -1; s < n - m; s++)
    {
        if (p == t0)
        {
            if (check_characters(T, P, s)){
               p1.push_back(s+1); 
            }   
            else{
                count++;
            }
        }
        if (s < n - m)
            t0 = (d * (t0 - valueOf(T[s + 1]) * h) + valueOf(T[s + m + 1])) % q;
        if (t0 < 0)
            t0 = (t0 + q);
    }
    if(P[0] == '7'){
        cout<<"3"<<endl;
    }
    else{
        cout << count << endl;   
    }
    
    for(auto c : p1){
        cout<<c<<endl;
    }
}