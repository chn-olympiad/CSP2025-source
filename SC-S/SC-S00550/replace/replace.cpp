#include <bits/stdc++.h>
using namespace std;

map <pair <string, string>, bool> mp;

int main ()
{
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    int n, q;
    scanf ("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        mp [make_pair (s1, s2)] = 1;
    }
    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size () != s2.size ())
        {
            printf ("0\n");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < s1.size (); i++)
        {
            for (int j = i; j < s1.size (); j++)
            {
                string s1x = s1.substr (0, i), s1y = s1.substr (i, (j - i + 1)), s1z;
                string s2x = s2.substr (0, i), s2y = s2.substr (i, (j - i + 1)), s2z;
                if (j != s1.size () - 1)
                {
                    s1z = s1.substr (j + 1), s2z = s2.substr (j + 1);
                }
                if (i == 0)
                {
                    s1x = s2x = "";
                }
                if (j + 1 == s1.size ())
                {
                    s1z = s2z = "";
                }
                if (!(s1x != s2x || s1z != s2z || mp [make_pair (s1y, s2y)] == 0))
                {
                    cnt++;
                }
            }
        }
        printf ("%d\n", cnt);
    }
    return 0;
}