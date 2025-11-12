#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int MOD = 998244353;
int n, m;
int s[N], c[N];
long long ans = 0;
bool vis[N];
int C[N];
void init()
{
    C[1] = 1;
    for (int i = 2; i <= 505; i++)
    {
        C[i] = C[i - 1] * i;
        C[i] %= MOD;
    }
}
void DFS(int k, int S)
{
    if (k > n)
    {
        if (S >= m)
        {
            ans++;
            ans %= MOD;
        }
        return;
    }
    if (S >= m)
    {
        int res = n - k + 1;
        ans += C[res];
        ans %= MOD;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            int x = k - 1 - S;
            if (c[i] <= x)
            {
                DFS(k + 1, S);
            }
            else
            {
                if (s[k] == 1)
                    DFS(k + 1, S + 1);
                else
                    DFS(k + 1, S);
            }
            vis[i] = 0;
        }
    }
}
void f1()
{
    init();
    DFS(1, 0);
    cout << ans << endl;
}
void f2()
{
    init();
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << C[n] << endl;
        return;
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        s[i] = ch - '0';
        sum += s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    if (n <= 18)
    {
        f1();
        return 0;
    }
    if (sum == n)
    {
        f2();
        return 0;
    }
    if (m == n)
    {
        if (sum != n)
        {
            cout << "0" << endl;
            return 0;
        }
        init();
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            cout << "0" << endl;
            return 0;
        }
        cout << C[n] << endl;
        return 0;
    }
    return 0;
}