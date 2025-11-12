#include<bits/stdc++.h>
//#pragma GCC	optimize(2)
#define int long long
using namespace std;

inline int read(){
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

struct edge{
	int u, v;
	int w;
};

bool cmp(edge a, edge b){
	if(a.w!=b.w) return a.w<b.w;
	else if(a.u!=b.u) return a.u<b.u;
	return a.v<b.v;
}

int n, m, k, ans, tot=1;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(), m=read(), k=read();
	vector<edge> gcity(n+1);
	vector<vector<int> > dis(n+1, vector<int>(n+1, -1));
	vector<vector<int> > gvillage(k+1, vector<int>(n+1));
	vector<int> vis(n+1, 0);
	vector<pair<bool, int> > ex(k+1);
	gcity[0].w=-LLONG_MAX;
	for(int i=1;i<=m;++i){
		gcity[i].u=read(), gcity[i].v=read(), gcity[i].w=read();
	}
	sort(gcity.begin(), gcity.end(), cmp);
	int u, v, w;
	vis[gcity[1].u]=1;
	for(int i=1;i<=m;++i){
		u=gcity[i].u, v=gcity[i].v, w=gcity[i].w;
		if(vis[v]>2) continue;
		tot++;
		++vis[v];
	}
	for(int i=1;i<=k;++i){
		ex[i].second=read();
		for(int j=1;j<=n;++j){
			gvillage[i][j]=read();
		}
	}
	cout<<tot;
	fclose(stdin);
	fclose(stdout);
	return 0;
}