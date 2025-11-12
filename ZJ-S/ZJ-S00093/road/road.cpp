#include<bits/stdc++.h>
using namespace std;
#define IO(fn) freopen(fn".in","r",stdin);freopen(fn".out","w",stdout);
typedef long long ll;
int n,m,k,tot;
const int N=5e4+54;
struct edge{
	int u,v,w;
	bool operator<(const edge B)const{
	return w<B.w;
	}
}E[N<<4];
namespace qqq1{
	int fa[N];
	int fnd(int x){
		return fa[x]=(fa[x]==x?x:fnd(fa[x]));
	}
	int rem,ans=0;
	void solve(){
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(E+1,E+tot+1);
		for(int i=1;i<=tot;i++){
			int x=fnd(E[i].u),y=fnd(E[i].v);
			if(x==y)continue;
			rem--;
			ans+=E[i].w;
			fa[x]=y;
			if(rem==1)break;
		}
		cout<<ans<<'\n';
	}
}
int c[N];
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>E[i].u>>E[i].v>>E[i].w;
	}tot=m;
	if(k==0){
		qqq1::solve();
	}
	else{
		for(int i=1;i<=k;i++){
			cin>>c[0];
			for(int i=1;i<=n;i++){
				cin>>c[i];
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					E[++tot].u=i;
					E[tot].v=j;
					E[tot].w=c[i]+c[j];
				}
			}
		}
		qqq1::solve();
	}
}
int main(){IO("road");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
}
