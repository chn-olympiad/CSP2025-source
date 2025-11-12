#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <typename type>
inline void read(type &x)
{
    x = 0; static bool flag; flag = 0; char ch = getchar();
    while (!isdigit(ch)) flag = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    flag ? x = -x : 0;
}

const int N = 2e5 + 5;
const LL INF = 1e18 + 7;

int n, q, ans;
string s[N][3], t[3], tmp;

bool rep(int j, int i)
{
    for (int p = 0; p < s[i][1].length(); p ++)
        if (t[1][j + p] != s[i][1][p]) return false;
    for (int p = 0; p < s[i][1].length(); p ++)
        tmp[j + p] = s[i][2][p];
    return true;
}

bool check()
{
    for (int i = 0; i < t[1].length(); i ++)
        if (tmp[i] != t[2][i]) return false;
    return true;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    read(n); read(q);
    for (int i = 1; i <= n; i ++)
        cin >> s[i][1] >> s[i][2];
    while (q --)
    {
        ans = 0;
        cin >> t[1] >> t[2];
        for (int i = 1; i <= n; i ++)
        {
            if (s[i][1].length() > t[1].length()) continue;
            for (int j = 0; j + s[i][1].length() - 1 < t[1].length(); j ++)
            {
                tmp = t[1];
                if (!rep(j, i)) continue;
                if (check()) ans ++;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;//Rem bless
}