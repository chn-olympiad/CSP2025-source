#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+7;
int n,m,k;
struct lu{
	int u,v,w;
};
vector <lu> a;
vector <int> c[13];
int cw[13];
bool cmp(lu x,lu y){
	return x.w<y.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a.push_back({u,v,w});
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>cw[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			c[i].push_back(w);
		}
	}
	for(int i=0;i<a.size();i++){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu!=fv){
			sum+=a[i].w;
			fa[fu]=fv;
		}
	}
	cout<<sum<<"\n";
	return 0;
}
