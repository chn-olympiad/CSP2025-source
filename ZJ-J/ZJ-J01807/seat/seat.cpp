#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> PII;
    const int N = 2e4 + 5, INF = 0x3f3f3f3f;
    inline int read()
    {
        int x = 0, f;
        char ch = getchar();
        while (!isdigit(ch) && ch != '-')
            ch = getchar();
        f = (ch == '-' ? (ch = getchar(), -1) : 1);
        while (isdigit(ch))
        {
            x = (x << 1) + (x << 3) + ch - '0';
            ch = getchar();
        }
        return x * f;
    }
}
using namespace Cosh_X;
int n, m, num, score, a[N];
inline bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = read(), m = read();
    num = n * m;
    for (int i = 1; i <= num; i++)
        a[i] = read();
    score = a[1];
    sort(a + 1, a + 1 + num, cmp);
    int nn = 1, mm = 1, flag = 1;
    for (int i = 1; i <= num; i++)
    {
        if (a[i] == score)
        {
            cout << mm << ' ' << nn << '\n';
            return 0;
        }
        if ((nn == n && flag == 1) || (nn == 1 && flag == -1))
            mm++, flag = -flag;
        else
            nn += flag;
    }
    return 0;
}

// g++ seat.cpp -std=c++14 -Wall -O2 -o seat