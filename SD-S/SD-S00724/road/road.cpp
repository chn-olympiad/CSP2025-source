#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k; 
struct node{
	
	int u, v, w;
	
} a[4000005]; 
int fa[4000005];

bool cmp (node xx, node yy){
	
	return xx.w < yy.w;
	
}

int find (int x){
	
	if (fa[x] == x) return x;
	else return fa[x] = find (fa[x]);
	
}

signed main()
{

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= m; i ++){
		
		cin >> a[i].u >> a[i].v >> a[i].w;
		
	}
	
	int x, ll = n, r = n;
	
	for (int i = 1; i <= k; i ++){
		
		cin >> x;
		r ++;
		
		for (int j = 1; j <= ll; j ++){
			
			cin >> x;
			m ++;
			a[m].u = r;
			a[m].v = j;
			a[m].w = x;
			
		}
		
	}
	
	for (int i = 1; i <= n; i ++) fa[i] = i;
	
	sort (a + 1, a + n + 1, cmp);
	
	int ans = 0;
	
	for (int i = 1; i <= m; i ++){
		
		int x = find (a[i].u), y = find (a[i].v);
		
		if (x != y){
			
			fa[x] = y;
			ans += a[i].w;
			
		}
		
	}
	
	cout << ans;
	
}

/*
5 6 0
1 4 1
4 5 1
2 5 8
3 5 2
1 2 1
2 3 9
*/

