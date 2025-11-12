#include<bits/stdc++.h>
using namespace std;
#define N 10007
#define int long long
#define A first
#define B second
#define pb push_back
#define piii pair<pair<int,int>,int>
int n,m,k,h[N],g[N][N],ans;
int fa[N];
vector<piii>v;
int Find(int x){
	if(fa[x]==x) return x;
	fa[x]=Find(fa[x]);
	return fa[x];
}void Union(int x,int y){
	if(Find(x)==Find(y)) return;
	fa[Find(x)]=Find(y);
}bool cmp(piii q,piii e){
	return q.B<e.B;
}
void treee(){
	sort(v.begin(),v.end(),cmp);
	for(auto i:v){
		int cur1=i.A.A,cur2=i.A.B,cur3=i.B;
		if(Find(cur1)!=Find(cur2))
			ans+=cur3,
			Union(cur1,cur2);
	}
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		v.pb({{max(a,b),min(a,b)},c});
	}for(int i=1;i<=k;++i){
		cin>>h[i];
		for(int j=1;j<=n;++j)
			cin>>g[i][j];
	}treee();cout<<ans<<endl;
	return 0;
}//20 expected
