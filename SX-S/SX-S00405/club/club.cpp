#include <bits/stdc++.h>
using namespace std;
int n,t,a[100010][3],cnt[3];
long long ans;
bool st[100010];
struct node
{
    int id,v;
    bool operator<(const node &x) const
    {
        return v>x.v;
    }
};
inline int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch<'0'||ch>'9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x = (x<<1)+(x<<3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    t = read();
    while(t--)
    {
        n = read();
        for (int i = 1;i <= n;i++) st[i] = 0;
        cnt[0] = cnt[1] = cnt[2] = ans = 0;
        priority_queue<node> q;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 0;j < 3;j++) a[i][j] = read();
            int k = 0;
            for (int j = 0;j < 3;j++) if (a[i][j] > a[i][k]) k = j;
            ans += a[i][k]; cnt[k]++;
        }
        int m = 0;
        for (int i = 0;i < 3;i++) if (cnt[i] > cnt[m]) m = i;
        swap(cnt[0],cnt[m]);
        for (int i = 1;i <= n;i++) swap(a[i][0],a[i][m]);
        if (cnt[0] > n/2)
        {
            m = 0;
            for (int i = 1;i <= n;i++)
            {
                if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
                {
                    m++;
                    q.push({i,a[i][0]-a[i][1]});
                    q.push({i,a[i][0]-a[i][2]});
                }
            }
            m -= n/2;
            while(m)
            {
                node t = q.top(); q.pop();
                if (st[t.id]) continue;
                st[t.id] = 1; m--;
                ans -= t.v;
                // cout << t.v << " " << t.id << "\n";
            }
        }
        cout << ans << "\n";
    }
    return 0;
}