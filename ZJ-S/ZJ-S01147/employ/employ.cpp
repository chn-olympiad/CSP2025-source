#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 998244353;
using ll = long long;
int n, m;
string s;
vector<int> c;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        c.push_back(x);
    }
    bool flagA = true;
    for (auto i : s)
    {
        if (i != '1')
        {
            flagA = false;
            break;
        }
    }
    if (flagA)
    {
        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
        return 0;
    }
    if (m == n)
    {
        for (auto i : s)
        {
            if (i == '0')
            {
                cout << 0 << endl;
                return 0;
            }
        }
        for (auto i : c)
        {
            if (i == 0)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        ll ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    sort(c.begin(), c.end());
    while (next_permutation(c.begin(), c.end()))
    {
        int kt = 0; // 录用人数
        int ct = 0; // 拒绝人数
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (c[i] - ct > 0)
                {
                    kt++;
                    if (kt == m)
                    {
                        ans++;
                        if (ans == MOD)
                        {
                            ans = 0;
                        }
                        break;
                    }
                }
                else
                {
                    ct++;
                }
            }
            if (s[i] == '0')
            {
                ct++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
// n!
// 1 => 1
// 2 => 2
// 3 => 6
// 考虑对每个元素进行离散化
// 则如果当前是 1, 将ans乘以当前还可以继续的人数
// 如果当前是 0，则将全体的耐心 -1， 如果有人的耐心为负数则将其剔除
// 似乎不行
// 考虑简单的 1 0 2 3
// s=1010
// 故第一位有四种可能