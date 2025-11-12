#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace StarRail{
	struct Edge{
		ll u,v,w;
	}e[1100005],ee[1100005];
	struct Cot{
		ll vu;
		ll v[10005];
	}c[15];
	int f[10015];
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	int n,m,k;
	ll ans=0;
	bool cmp1(Edge x,Edge y){
		return x.w<y.w;
	}
	void sub1(){
		for(int i=1;i<=n;i++)f[i]=i;
		sort(e+1,e+m+1,cmp1);
		for(int i=1;i<=m;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv){
				f[fu]=fv;
				ans+=e[i].w;
			}
		}
		cout<<ans<<'\n';
	}
	void sub2(){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(c[i].v[j]==0){
					for(int l=1;l<=n;l++){
						if(l==j)continue;
						e[++m].u=j;
						e[m].v=l;
						e[m].w=c[i].v[l];
					}
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)f[i]=i;
		sort(e+1,e+m+1,cmp1);
		for(int i=1;i<=m;i++){
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv){
				f[fu]=fv;
				ans+=e[i].w;
			}
		}
		cout<<ans<<'\n';
	}
	void sub3(){
		
	}
	void sub4(){
		ans=1e18;
		for(int i=0;i<(1<<k);i++){
			int mm=m;
			for(int j=1;j<=m;j++){
				ee[j].u=e[j].u;
				ee[j].v=e[j].v;
				ee[j].w=e[j].w;
			}
			ll aans=0;
			for(int j=1;j<=k;j++){
				if(i&(1<<j-1)){
					aans+=c[j].vu;
					for(int l=1;l<=n;l++){
						ee[++mm].u=n+j;
						ee[mm].v=l;
						ee[mm].w=c[j].v[l];
					}
				}
			}
			for(int j=1;j<=n+k;j++)f[j]=j;
			sort(ee+1,ee+mm+1,cmp1);
			for(int j=1;j<=mm;j++){
				int fu=find(ee[j].u),fv=find(ee[j].v);
				if(fu!=fv){
					f[fu]=fv;
					aans+=ee[j].w;
				}
			}
			ans=min(ans,aans);
		}
		cout<<ans<<'\n';
	}
	void main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
		//freopen("road4.in","r",stdin);
		//freopen("road4.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		cin>>n>>m>>k;
		bool flaga=1;
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		for(int i=1;i<=k;i++){
			bool flagg=0;
			cin>>c[i].vu;
			if(c[i].vu)flaga=0;
			for(int j=1;j<=n;j++){
				cin>>c[i].v[j];
				if(c[i].v[j])flagg=1;
			}
			flaga&=flagg;
		}
		if(k==0)sub1();
		else if(flaga)sub2();
		else
		sub4();
	}
}
int main(){
	StarRail::main();
}

