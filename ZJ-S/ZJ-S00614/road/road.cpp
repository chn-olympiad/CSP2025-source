#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=10005;
long long ans,c[11];
int val[N],nxt[N],head[N],s[N],a[M],tot,n,m,k,u,v,w,e,l,g;
void x(int u,int v,int w){
	val[++tot]=v;
	s[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
int main(){
	cin.tie();
	cout.tie();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		x(u,v,w);
		x(v,u,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>g;
			c[i]+=g;
		}
	}
	a[1]=1;
	for(int i=1;i<=n;i++){
		if(i==n && !e) break;
		int z=2147483647,y=0;
		for(int j=head[i];j;j=nxt[j]){
			if(!a[val[j]] || !a[i]){
				z=min(z,s[j]);
				if(z==s[j]) y=val[j];
			}
		}
		if(y) ans+=z;
		a[y]=1;
		if(y==0) e=1;
	}
	for(int i=1;i<=k;i++) ans=min(ans,c[i]);
	cout<<ans;
	return 0;
}
