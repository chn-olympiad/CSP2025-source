#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20015;

int T, n, m, k, w[15][N];
int cnt, ans;
int fa[N];
struct node{
    int x, y, z;
}g[1020015], h[N];

//////////////////////////////////
bool cmp(node a, node b)
{
    return a.z < b.z;
}
bool cmp2(node a, node b)
{
    return a.z > b.z;
}
//////////////////////////////////
int get(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}
//////////////////////////////////

void mintree()
{
    for (int i = 1; i <= n; i++) fa[i] = i;
    sort(g + 1, g + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int x = g[i].x, y = g[i].y;
        int xx = get(x), yy = get(y);
        if (xx == yy) continue;
        ans += g[i].z;
        h[++cnt].x = x, h[cnt].y = y, h[cnt].z = g[i].z;
        fa[xx] = yy;
    }
}
////////////////////////////////////

void tp()
{
    for (int i = 1; i <= k; i++)
    {
        int p = 1;
        for (int j = 1; j <= n; j++) 
        {
            if (w[i][j] == 0) 
            {
                p = j; break;
            }
        }

        for (int j = 1; j <= n; j++)
        {
            if (j == p) continue;
            h[++cnt].x = p, h[cnt].y = j, h[cnt].z = w[i][j];
        }
    }
    ans = 0;
    sort(h + 1,  h + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++) fa[i] = i;
    for (int i = 1; i <= cnt; i++)
    {
        int x = h[i].x, y = h[i].y;
        int xx = get(x), yy = get(y);
        if (xx == yy) continue;
        ans += h[i].z;
        fa[xx] = yy;
    }
    cout << ans << "\n";
    return;
}

////////////////////////////////////
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        int fl = 1;
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[i].x = x; g[i].y = y; g[i].z = z;
        }
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= n; j++) 
            {
                cin >> w[i][j];
                if (w[i][0] > 0) fl = 0;
            }
                
        
        ans = 0, cnt = 0;
        mintree();

        if (k == 0) 
        {
            cout << ans << "\n";
            continue;
        }

        tp();
    }
    return 0;
}