//石丰源 SN_S00556 安康市长兴综合高级中学 
#include<map>
#include<queue>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn int(1e4+10)
#define maxm int(1e6+10)
#define ll long long
typedef pair<int,int> pii;
inline int read(){
	char c=getchar(); int t=1,k=0;
	while('0'>c||c>'9'){if(c=='-') t=-1; c=getchar();}
	while('0'<=c&&c<='9'){k=k*10+(c^48); c=getchar();}
	return t*k;
}
int fth[maxn];
inline int find(int x){
	if(fth[x]==x) return x;
	return fth[x]=find(fth[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	int c[15],u[m+10],v[m+10],a[15][n+10],cnt=0;
	ll ans=0;
	priority_queue<pii,vector<pii>,greater<pii> > p;
	for(int i=1;i<=m;i++){
		u[i]=read(),v[i]=read();ll w=read();
		p.push(make_pair(w,i));
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();	
	}
	for(int i=1;i<=n;i++) fth[i]=i;
	while(p.size()){
		int id=p.top().second,wi=p.top().first; p.pop();
		if(find(u[id])==find(v[id])) continue;
		ans+=wi;
		fth[find(u[id])]=fth[find(v[id])];
		cnt++;
		if(cnt==n-1) break;
	}
	printf("%lld",ans);
	return 0;
}
