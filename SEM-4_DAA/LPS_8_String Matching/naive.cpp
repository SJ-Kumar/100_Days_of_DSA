/*
Given a text T and a pattern P, implement the naive algorithm to print the non-overlapping positions of P in T. For example, if T is "aaaaaaaa" and pattern is "aa" then the code should print 0, 2, 4, 6 (programming indices - non-over lapping)

Input Format

First line contains the text, T

Next line contains the pattern, P

Output Format

Print non-overlapping indices, one value in one line

*/


void naive_string_matcher(string T, string P)
{
    int n = T.length();
    int m = P.length();
    int s = -1;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = -1; // Initialize array with -1
    }

    int i = 0;
    while (s <= n - m)
    {
        if (check_pattern(T, P, s))
        {
            a[i] = s+1;
            i++;
            s += m;
        }
        else
        {
            s++;
        }
    }

    for (int j = 0; j < i; j++)
    {
        cout << a[j] << endl;
    }
}
