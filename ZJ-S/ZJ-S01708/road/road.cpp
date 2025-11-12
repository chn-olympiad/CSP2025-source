#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e4;
const int M = 2e6;
int n, m, k;
ll ans;
int fa[N];
int countries[15][N];
int special[15];
struct edge{
    int from, to, weight;
} edges[M];

bool cmp(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    int edge_size = m;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    for(int i=1; i<=k; i++)
    {
    	scanf("%d", &countries[i][0]);
    	for(int j=1; j<=n; j++){
            scanf("%d", &countries[i][j]);
            if(countries[i][j] == 0){
                special[i] = j;
            }
        }
        for(int j=1; j<=n; j++){
            edge E;
            if(j == special[i]) continue;
            E.from = special[i], E.to = j, E.weight = countries[i][j];
            edges[++edge_size] = E;
        }
	}
    sort(edges+1, edges+edge_size+1, cmp);
    for(int i=1; i<=n; i++){
        fa[i] = i;
    }
    for (int i=1; i<=m; i++)
    {
        int A = edges[i].from, B = edges[i].to;
        if(find(A) != find(B))
        {
            fa[fa[B]] = fa[A];
            ans += edges[i].weight;
        }
    }
    cout << ans;
    return 0;
}
