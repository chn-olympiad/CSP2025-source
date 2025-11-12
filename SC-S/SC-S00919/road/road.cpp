#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')	f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')	x = (x<<3) + (x<<1) + (c ^ 48),c = getchar();
	return x * f;
}
const int N = 10015,M = 1000005,W = 1050,K = 13;
const ll I = 2e13;
struct edge{
	int u,v;
	ll w;
	friend bool operator<(edge x,edge y){
		return x.w < y.w;
	}
}a[M],b[N],g[W][N],c[K][N],e[M*2];
int n,m,k;
int cnt;
int fa[N],sz[N];
int find(int x){
	if(fa[x] == x)	return x;
	return fa[x] = find(fa[x]);
}
bool merge(int x,int y){
	x = find(x),y = find(y);
	if(x == y)	return 0;
	fa[x] = y;
	sz[y] += sz[x];
	return 1;
}
void init(){
	for(int i = 1;i <= n+k;i++)	fa[i] = i,sz[i] = 1;
}
ll kr(int s){
	init();
	ll num = 0;
	int top = 0;
//	printf("kr(%d)\n",s);
	for(int i = 0;i < k;i++)
		if(s>>i&1)	num += c[i+1][0].w;
//	printf("num = %lld\n",num);
	for(int i = 1;i <= cnt;i++)	e[++top] = b[i];
	for(int i = 0;i < k;i++)
		if(s>>i&1)
			for(int j = 1;j <= n;j++)
				e[++top] = c[i+1][j];
	sort(e+1,e+1+top);
//	for(int i = 1;i <= top;i++)	printf("(%d,%d,%lld)\n",e[i].u,e[i].v,e[i].w);
	int cnt = 0;
	for(int i = 1;i <= top;i++)
		if(merge(e[i].u,e[i].v)){
			if(s == 3 && e[i].w == 5)	cnt++;
			num += e[i].w;
		}
//	if(s == 3)	printf("cnt = %d\n",cnt);
	return num;
}
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 1;i <= m;i++)	a[i].u = read(),a[i].v = read(),a[i].w = read();
	for(int i = 1;i <= k;i++)
		for(int j = 0;j <= n;j++)	c[i][j].u = i+n,c[i][j].v = j,c[i][j].w = read();
	sort(a+1,a+1+m);
	for(int i = 1;i <= k;i++)	sort(c[i]+1,c[i]+1+n);
//	for(int i = 1;i <= k;i++)
//		for(int j = 1;j <= n;j++)	printf("(%d,%lld)%c",c[i][j].v,c[i][j].w," \n"[j==n]);
	init();
	ll sum = 0;
	for(int i = 1;i <= m;i++){
		int u = a[i].u,v = a[i].v,w = a[i].w;
//		printf("(%d,%d,%d)\n",u,v,w);
		if(merge(u,v))	sum += w,b[++cnt] = {u,v,w};
	}
//	printf("sum = %lld\n",sum);
	ans = sum;
	int u = (1<<k) - 1;
	int fl = 1;
	for(int i = 1;i <= k;i++)
		if(c[i][0].w)	fl = 0;
	for(int s = fl * u;s <= u;s++){
		ll num = kr(s);
		ans = min(ans,num);
//		printf("s = %d | num = %lld\n",s,num);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/ 