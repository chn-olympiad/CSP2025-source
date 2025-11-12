#include<bits/stdc++.h>

#define int long long

#define maxn 1000005

#define INF (int)(1e18)

#define double long double

using namespace std;

int n,m,k;

struct edge{
	
	int s,e,d;
	
	int pd;
	
}a[1000005],b[200005];

bool cmp(edge a,edge b){
	
	if(a.pd == b.pd) return a.d < b.d;
	
	else return a.pd > b.pd;
	
}

int fa[10015],sz[10015];

int c[15],cost[15][10005];

//bool pd[1505];

int get_fa(int x){
	
	return (x == fa[x] ? x : fa[x] = get_fa(fa[x]));
	
}

signed main(){

	ios::sync_with_stdio(0);
	
	cin.tie(0);
	
	cout.tie(0);
	
	freopen("road.in","r",stdin);
	
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	
	for(int i = 1;i <= m;++ i){
		
		cin >> a[i].s >> a[i].e >> a[i].d;
		
		a[i].pd = 0;
		
	}
	
	for(int i = 1;i <= n;++ i){
		
		fa[i] = i,sz[i] = 1;
		
	}
	
	int ans = 0;
	
	sort(a + 1,a + m + 1,cmp);
	
	for(int i = 1;i <= m;++ i){
		
		int s = a[i].s,e = a[i].e,d = a[i].d;
		
		int ss = get_fa(s),ee = get_fa(e);
		
		if(ss != ee){
			
			ans += d;
			
			if(sz[ss] < sz[ee]) fa[ss] = ee,sz[ee] += sz[ss];
			
			else fa[ee] = ss,sz[ee] += sz[ss];
			
			a[i].pd = 1;
			
		}
		
	}
	
	for(int i = 1;i <= k;++ i){
		
		cin >> c[i];
		
		for(int j = 1;j <= n;++ j) cin >> cost[i][j];
		
	}
	
	sort(a + 1,a + m + 1,cmp);
	
	int del = 0;
	
	for(int s = 1;s < (1ll << k);++ s){
		
//		if((s & del) != 0) continue;
		
		int nowans = 0;
		
		for(int i = 1;i <= n - 1;++ i){
			
			b[i] = a[i];
			
		}
		
		int cnt = n - 1;
		
		int num = n;
		
//		bool bec = 0;
		
		for(int i = 1;i <= k;++ i){
			
			if(!(s & (1ll << (i - 1)))) continue;
			
			nowans += c[i];
			
			++ num;
			
			for(int j = 1;j <= n;++ j){
				
				b[++ cnt].s = num;
				
				b[cnt].e = j;
				
				b[cnt].d = cost[i][j];
				
				b[cnt].pd = 1;
				
			}
			
		}
		
//		if(bec) continue;
		
		sort(b + 1,b + cnt + 1,cmp);
		
		for(int i = 1;i <= num;++ i) fa[i] = i,sz[i] = 1;
		
		for(int i = 1;i <= cnt;++ i){
			
			int s = b[i].s,e = b[i].e,d = b[i].d;
			
			int ss = get_fa(s),ee = get_fa(e);
			
			if(ss != ee){
				
				if(sz[ss] < sz[ee]) fa[ss] = ee,sz[ee] += sz[ss];
				
				else fa[ee] = ss,sz[ss] += sz[ee];
				
				nowans += d;
				
			}
			
		}
		
		if(ans < nowans) del = (del | s);
		
		ans = min(ans,nowans);
		
	}
	
	cout << ans << "\n";
	
	return 0;

}
/*

*/
