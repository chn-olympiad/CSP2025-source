#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
string s1[MAXN], s2[MAXN];
int res = 0;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
    }

    while (q--)
    {
        res = 0;
        string t1, t2;
        cin >> t1 >> t2;
        int l = t1.size();
        for (int i = 1; i <= n; i++)
        {
            int sl = s1[i].size();
            string t = "";
            for (int j = 0; j < l; j++)
            {
                bool flag = true;
                for (int k = 0; k < sl; k++)
                {
                    if (s1[i][k] != t1[j + k])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    string tt = t;
                    tt += s2[i];
                    for (int k = j + sl; k < l; k++)
                    {
                        tt += t1[k];
                    }
                    if (tt == t2) res++;
                }
                t += t1[j];
            }
        }
        cout << res << '\n';
    }

    return 0;
}
