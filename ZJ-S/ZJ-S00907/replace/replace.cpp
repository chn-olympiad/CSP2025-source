#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
const int B = 1145141;
const int N = 2e5 + 5;
const int M = 5e6 + 5;

inline u64 hsh(const string &s)
{
    u64 res = 0;
    for (auto &x : s)
    {
        res = res * B + x;
    }
    return res;
}
int n, m, q;
string s, t;
u64 pw[M], hs[M], ht[M];
struct node
{
    u64 x, y;
    int len;
} a[N];

void Main()
{
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * B;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> t;
        a[i] = node{hsh(s), hsh(t), (int)s.size()};
    }
    sort(a + 1, a + n + 1, [&](const node &x, const node &y)
         { return x.len > y.len; });
    while (q--)
    {
        cin >> s >> t;
        m = s.size();
        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= m; i++)
        {
            hs[i] = hs[i - 1] * B + s[i];
        }
        for (int i = 1; i <= m; i++)
        {
            ht[i] = ht[i - 1] * B + t[i];
        }
        int dif = 0;
        for (int i = m; i > 0; i--)
        {
            if (s[i] != t[i])
            {
                dif = i;
                break;
            }
        }
        int res = 0, st = 1;
        for (int i = 1; i <= m; i++)
        {
            while (st <= n && i + a[st].len - 1 > m)
                ++st;
            int idx = st;
            while (idx <= n && i + a[idx].len - 1 >= dif)
            {
                // cerr << "> " << i << ' ' << i + a[idx].len - 1 << endl;
                if (hs[i + a[idx].len - 1] - hs[i - 1] * pw[a[idx].len] == a[idx].x && ht[i + a[idx].len - 1] - ht[i - 1] * pw[a[idx].len] == a[idx].y)
                    ++res;
                ++idx;
            }
            if (s[i] != t[i])
                break;
        }
        cout << res << '\n';
    }
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Main();
    return 0;
}