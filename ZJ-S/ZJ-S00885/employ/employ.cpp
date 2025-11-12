#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define mod 998244353

int A(int n, int m)
{
    int ans = 1;
    for (int i = m; i <= n; i++)
    {
        ans = ans * i % mod;
    }
    return ans;
}

int n, m;
char s[N];
int pre[N];
int cntpre[N];
int cntc[N];
int c[N];

int main()
{
	freopen("replace.in",  "r", stdin);
	freopen("replace.out", "w", stdout);
    cin.tie(nullptr); cout.tie(nullptr); cout.sync_with_stdio(false);
	cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        pre[i] = pre[i-1] + s[i];
        cntpre[pre[i]]++;
        cntc[c[i]]++;
    }
    sort(c+1, c+n+1);
    if (n == m)
    {
        int shengyu = 0;
        int ans = 1;
        for (int i = n; i >= 0; i--)
        {
            if (s[i] + shengyu < c[i])
            {
                cout << 0;
                return 0;
            }
            else
            {
                ans = ans * A(s[i] + shengyu, c[i]) % mod;
            }
            shengyu += c[i] - s[i];
        }
        cout << ans;
    }
    else
    {
        if (n <= 10)
        {
            int ans = 0;
            do
            {
                int cnt = 0, now = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (s[i] == '0') now++;
                    if (c[i] > now) cnt++, now++;
                }
                if (cnt >= m) ans++;
            } while (next_permutation(c+1, c+1+n));
            cout << ans;
        }
        else
        {
            cout << 0;
        }
    }
	return 0;
}
