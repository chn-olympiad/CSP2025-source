#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 1e6+5;
int n,m,k;
int fa[N],c[N];
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
struct bb{
	int u,v,w;
	bool operator<(const bb&x)const{
		return w<x.w;
	}
}in[N];
struct aa{
	int u,w;
	bool operator<(const aa&x)const{
		return w<x.w;
	}
};
aa a[12][10005];int vl[12][10005];
vector<aa>E[N];
bool vis[N];int st[12],sta[12],tp;
priority_queue<aa>q;
bool Chk(int i,int x){
	return i<=k&&((x>>(i-1))&1);
}
int Mi[12];
int chk(int x){
	int res = 0;tp = 0;
	for(int i=1;i<=n+k;i++){
		vis[i] = 0;
	}
	for(int i=1;i<=k;i++){
		if((x>>(i-1))&1){
			res+=c[i];
			sta[++tp] = i;
		}
		st[i] = 1;Mi[i] = 1e18;
	}
	while(!q.empty()){
		q.pop();
	}
	vis[1] = 1;
	for(aa x:E[1]){
		q.push((aa){x.u,-x.w});
	}
	for(int j=1;j<=tp;j++){
		Mi[sta[j]] = vl[sta[j]][1];
	}
	for(int i=2;i<=n+tp;i++){
		int u = 0,dis = 1e18;
		while(!q.empty()){
			int v = q.top().u;
			if(vis[v]){
				q.pop();
			}else{
				u = v;dis = -q.top().w;
				break;
			}
		}
		for(int j=1;j<=tp;j++){
			int v = sta[j];
			if(vis[v+n]){
				while(st[v]<=n&&vis[a[v][st[v]].u]){
					st[v]++;
				}
				if(st[v]<=n){
					if(dis>a[v][st[v]].w){
						u = a[v][st[v]].u;dis = a[v][st[v]].w;
					}
				}
			}else{
				if(dis>Mi[v]){
					u = v+n;dis = Mi[v];
				}
			}
		}
		vis[u] = 1;
		res+=dis;
		for(aa x:E[u]){
			q.push((aa){x.u,-x.w});
		}
		if(u<=n){
			for(int j=1;j<=tp;j++){
				Mi[sta[j]] = min(Mi[sta[j]],vl[sta[j]][u]);
			}
		}
	}
//	cout<<"X:"<<x<<" "<<res<<"\n";
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read();m = read();k = read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u = read();v = read();w = read();
		in[i] = (bb){u,v,w};
	}
	sort(in+1,in+1+m);
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	int ans = 0;
	for(int i=1;i<=m;i++){
		int u = find(in[i].u),v = find(in[i].v);
		if(u!=v){
			E[in[i].u].push_back((aa){in[i].v,in[i].w});
			E[in[i].v].push_back((aa){in[i].u,in[i].w});
			fa[v] = u;
			ans+=in[i].w;
		}
	}
	for(int i=1;i<=k;i++){
		c[i] = read();
		for(int j=1;j<=n;j++){
			a[i][j].w = read();
			a[i][j].u = j;
			vl[i][j] = a[i][j].w;
		}
		sort(a[i]+1,a[i]+1+n);
	}
	for(int i=1;i<(1<<k);i++){
		ans = min(ans,chk(i));
	}
	cout<<ans<<"\n";
	return 0;
}

