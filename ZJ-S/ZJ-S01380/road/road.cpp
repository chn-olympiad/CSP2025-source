#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
int n,m,k;
int c[N];
struct node{
	int a,b,c,id;
};
bool cmp(node a,node b){
	return a.c<b.c;
}
vector<node>e;
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
bool st[20];
ll klu(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	ll res=0;
	for(int i=0;i<(int)e.size();i++){
		int x=e[i].a,y=e[i].b,w=e[i].c,id=e[i].id;
		if(st[id]==0)continue;
		if(find(x)!=find(y)){
			fa[find(x)]=find(y);
			res+=w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e.push_back({a,b,c,0});
	}
	int f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])f=0;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			e.push_back({n+i,j,x,i});
		}
	}
	sort(e.begin(),e.end(),cmp);
	st[0]=1;
	if(f){
		for(int i=1;i<=k;i++){
			st[i]=1;
		}
		ll ans=klu();
		cout<<ans<<'\n';
		return 0;
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll sum=0;
		for(int j=0;j<k;j++){
			st[j+1]=(i&(1<<j));
			if(st[j+1]==1){
				sum+=c[j+1];
			}
		}
		sum+=klu();
		ans=min(ans,sum);
	}
	cout<<ans<<'\n';
	return 0;
}