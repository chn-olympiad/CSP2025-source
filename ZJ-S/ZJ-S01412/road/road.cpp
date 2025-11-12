#include<bits/stdc++.h>
#define int long long
#define void inline void
using namespace std;
const int maxn = 1e+6 + 6, N = 1e+5 + 4;
int n, m, k, atot, gt, O, p1, p2, np;
int fa[maxn], sz[maxn], w[15][N], c[15];
bool vis[15][N], vs[15];
map<int, int> mp[N];
vector<int> v[N];
struct E
{
    int x, y, z;
    friend bool operator < (const E &x, const E &y)
    {
        return x.z < y.z;
    }
}e[maxn], a[maxn], b[15];
inline int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dfs(int p, int fa)
{
    if (p == O + n)
    {
        gt = 0;
        p1 = 0;
        return;
    }
    if (gt > w[O][p] && !vis[O][p])
    {
        gt = w[O][p];
        p1 = p;
    }
    for (int i : v[p])
    {
        if (i != fa && !mp[p].count(i))
        {
            dfs(i, p);
        }
    }
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].x >> e[i].y >> e[i].z;
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int x = find(e[i].x), y = find(e[i].y);
        if (x != y)
        {
            cnt++;
            if (sz[x] < sz[y])
            {
                swap(x, y);
            }
            fa[y] = x;
            sz[x] += sz[y];
            v[e[i].x].push_back(e[i].y);
            v[e[i].y].push_back(e[i].x);
            a[++atot] = {e[i].x, e[i].y, e[i].z};
            ans += e[i].z;
            if (cnt == n - 1)
            {
                break;
            }
        }
    }
    int res = k;
    for (int i = atot; i; i--)
    {
    	int p = 0, pp = 1e18;
        for (int j = 1; j <= k; j++)
        {
        	if (!res && !vs[j])
        	{
        		continue;
			}
            O = j;
            int oo = c[j];
            gt = 1e18;
            p1 = p2 = 0;
            dfs(a[i].x, a[i].y);
            p2 = p1;
            oo += gt, gt = 1e18;
            dfs(a[i].y, a[i].x);
            oo += gt;
            b[j] = {oo, p1, p2};
            if (oo < a[i].z)
            {
            	if (oo < pp)
            	{
            		p = j, pp = oo;
				}
            }
            
        }
        if (pp < a[i].z)
        {
        	int oo = b[p].x, p1 = b[p].y, p2 = b[p].z, j = p;
            ans -= a[i].z;
            mp[a[i].x][a[i].y] = mp[a[i].y][a[i].x] = 1;
            ans += oo;
            if (!vs[j])
            {
            	res--;
			}
            vis[j][p1] = vis[j][p2] = 1;
            c[j] = 0;
            vs[j] = 1;
            if (p1)
            {
                v[p1].push_back(n + j), v[n + j].push_back(p1);	
			}
            if (p1 != p2 && p2)
            {
                v[p2].push_back(n + j), v[n + j].push_back(p2);
            }
        }
    }
    cout << ans;
    return 0;
}

