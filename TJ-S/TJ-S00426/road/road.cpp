#include<bits/stdc++.h>
using namespace std;
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
#define endl '\n'


// 1554 期望 20 
// 实在写不出来了，这道还是很满意的，写了一个小时还是很有成效的 
constexpr int N1 = 1e4 + 5;
constexpr int N2 = 1e6 + 5;
struct line{
	int u,v,w,id;
}a[N2];
int cost[N1],cid[N1];
bool flag[N1];
bool cmp(line x,line y){
	return x.w < y.w;
}
signed main(){
	fileIO("road");
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	memset(cost,0x3f,sizeof cost);
	for(int i = 1;i <= m;i ++){
		cin >> a[i].u >> a[i].v >> a[i].w;
		a[i].id = i;
		if(a[i].w < cost[a[i].u])cost[a[i].u] = a[i].w,cid[a[i].u] = a[i].id;
		if(a[i].w < cost[a[i].v])cost[a[i].v] = a[i].w,cid[a[i].v] = a[i].id;
	}
	for(int i = 1;i <= k;i ++){
		// 1~4 has no k :) 
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++){
		if(!flag[cid[i]])ans += cost[i],flag[cid[i]] = true;
	}
	cout << ans << endl; 
	return 0;
}

