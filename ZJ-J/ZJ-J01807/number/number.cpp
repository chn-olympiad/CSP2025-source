#include <bits/stdc++.h>
namespace Cosh_X
{
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> PII;
    const int N = 2e5 + 5, INF = 0x3f3f3f3f;
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
int t[12];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char ch = getchar();
    while (isdigit(ch) || ('a' <= ch && ch <= 'z'))
    {
        if (isdigit(ch))
            t[ch - '0']++;
        ch = getchar();
    }
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= t[i]; j++)
            putchar(i + '0');
    }
    cout << '\n';
    return 0;
}

// g++ number.cpp -std=c++14 -Wall -O2 -o number