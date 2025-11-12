#include<bits/stdc++.h>
using namespace std;
const int M=2000004,N=20004;
int n,m,k,sum;
struct E{
	int u,v,w;
	bool operator<(const E&b)const{return w<b.w;}
}e[N];
struct DSU{
	int pa[N];
	DSU(){
		for(int i=1;i<=N-4;i++) pa[i]=i;
	}
	int find(int x){
		return pa[x]==x?x:pa[x]=find(pa[x]);
	}
	void merge(int x,int y){
		int X=find(x),Y=find(y);
		pa[X]=pa[Y];
	}
};
int MST(int m,int sum){
	sort(e+1,e+1+m);
	DSU dsu;
	for(int i=1;i<=m;i++){
		if(dsu.find(e[i].u)!=dsu.find(e[i].v)){
			dsu.merge(e[i].u,e[i].v);
			sum+=e[i].w;
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("raod.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int ans=MST(m,0),nn=n;
	for(int i=1;i<=k;i++){
		int s;cin>>s;sum+=s;
		for(int j=1;j<=n;j++){
			cin>>e[j+m].w;e[j+m].u=nn+j,e[j+m].v=j;
		}
		m+=n;nn+=n;
		ans=min(ans,MST(m,sum));
		cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
