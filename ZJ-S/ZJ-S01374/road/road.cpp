#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6 + 5,N = 1e5 + 5;
struct edge{
	int u,v,w,us;
}e[M],d[M],num[11][N],t[M],g[M];
int n,m,k,f[N],c[11],tmp[N],ans = 1e18;
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}
bool cmp(edge x,edge y){
	return x.w < y.w;
}
int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}
void merge(int id,int len){
	int x = 1,y = 1;
	for(int i=1;i<=n-1+len;i++){
		if(y >= n || t[x].w < num[id][y].w) g[i] = t[x],++ x;
		else g[i] = num[id][y],++ y;
	}
	for(int i=1;i<=n-1+len;i++) t[i] = g[i];
}
void solve(int st){
	for(int i=1;i<=n;i++) f[i] = i;
	int tot = n-1,sum = 0;
	for(int i=1;i<=n-1;i++) t[i] = d[i];
	for(int i=1;i<=k;i++)
		if(st & (1 << i-1)){
			merge(i,tot); sum += c[i];
			tot += n-1;
		}
	int cnt = 0;
	for(int i=1;i<=tot;i++){
		int a = find(t[i].u),b = find(t[i].v);
		if(a == b) continue;
		++ cnt,f[a] = b,sum += t[i].w;
		if(cnt == n-1) break;
	}
	ans = min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i=1;i<=n;i++) f[i] = i;
	for(int i=1;i<=m;i++) e[i].u = read(),e[i].v = read(),e[i].w = read();
	sort(e+1,e+m+1,cmp);
	int cnt = 0;
	for(int i=1;i<=m;i++){
		int a = find(e[i].u),b = find(e[i].v);
		if(a == b) continue;
		e[i].us = 1,++ cnt;
		f[a] = b; if(cnt == n - 1) break;
	}
	cnt = 0;
	for(int i=1;i<=m;i++) if(e[i].us) d[++ cnt] = e[i];
	//for(int i=1;i<=n-1;i++) cout<<"d: "<<d[i].u<<" "<<d[i].v<<" "<<d[i].w<<endl;
	tmp[0] = 1e18;
	for(int i=1;i<=k;i++){
	    int idx = 0,mx = 0;
		c[i] = read();
		for(int j=1;j<=n;j++){
			tmp[j] = read();
			if(tmp[mx] > tmp[j]) mx = j;
		}
		c[i] += tmp[mx];
		for(int j=1;j<=n;j++) if(j != mx){
			++ idx;
			num[i][idx].u = mx,num[i][idx].v = j;
			num[i][idx].w = tmp[j];
		}
		sort(num[i]+1,num[i]+n,cmp);
	}
	for(int st=0;st<(1<<k);st++) solve(st);
	printf("%lld\n",ans);
	return 0;
}
