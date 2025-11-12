#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LYT ios::sync_with_stdio(0),cin.tie(0)
#define N 1000010
int n,m,k;
struct node{
	int u,v,w;
}a[N];
int s[N];
int findfa(int x){
	return s[x] == x ? x : s[x] = findfa(s[x]);
}
bool cmp(node x,node y){
	return x.w < y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1;i <= k;i++){
		for(int i = 1;i <= n+1;i++){
			int x;
			cin >> x;
		}
	}
	for(int i = 1;i <= n;i++) s[i] = i;
	sort(a+1,a+m+1,cmp);
	int ans = 0;
	for(int i = 1;i <= m;i++){
		if(findfa(a[i].u) != findfa(a[i].v)){
			s[findfa(a[i].u)] = findfa(a[i].v);
			ans += a[i].w; 
		}
	}
	cout << ans;
	return 0;
}
