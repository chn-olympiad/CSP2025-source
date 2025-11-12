#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11;
long long n,m,k,u,v,len,c[N],b[N],ans;
bool vis[N];
int tot,pre[N],f[N];
struct data {
	int to,len,nxt;
} a[N];
struct data2 {
	long long len,u,v;
}fr;
bool operator<(const data2 a,data2 b) {
	return a.len>b.len;
}
priority_queue<data2>q;
void add(int u,int v,int len) {
	a[++tot]= {v,len,pre[u]};
	pre[u]=tot;
	return ;
}
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void unin(int u,int v){
	int fu=find(u),fv=find(v);
	if(fu!=fv)f[fu]=fv;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1; i<=m; i++) {
		scanf("%lld%lld%lld",&u,&v,&len);
		add(u,v,len),add(v,u,len);
		q.push({len,u,v});
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1; i<=k; i++) {
		scanf("%lld",&c[i]);
		for(int j=1; j<=n; j++) {
			scanf("%lld",&b[j]);
			add(j,i+k,b[j]+c[i]);
			add(i+k,j,b[j]+c[i]);
		}
	}
	ans=0;
	while(!q.empty()) {
		fr=q.top();
		q.pop();
		int u=fr.u;
		int v=fr.v;
		if(find(u)==find(v))continue;
		ans+=fr.len;
		unin(u,v);
		for(int i=pre[u]; i; i=a[i].nxt) {
			int to=a[i].to;
			if(find(to)!=find(u)) {
				q.push({a[i].len,u,to});
			}
		}
		for(int i=pre[v]; i; i=a[i].nxt) {
			int to=a[i].to;
			if(find(to)!=find(v)) {
				q.push({a[i].len,v,to});
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

/*
4 5 0
1 2 1
2 3 2
3 4 1
4 1 1
4 2 1

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
