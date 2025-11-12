#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e7+10;
struct node{
	int u,v,w;
}q[N];
ll n,m,k,ans;
int fa[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int d){
	if(d==fa[d])return d;
	else return find(fa[d]);
}
void solve(){
	ll ct=m;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=ct;i++){
		int x=find(q[i].u),y=find(q[i].v);
		if(x==y)continue;
		ans+=q[i].w;
		fa[q[i].v]=fa[q[i].u]; 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,cw;
		cin>>u>>v>>cw;
		q[i].u=u;q[i].v=v;q[i].w=cw;
	}
	for(int i=1;i<=k;i++){
		int c,a;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
			q[++m].u=n+i;
			q[m].v=i;
			q[m].w=a+c;
		}
	}
	sort(q+1,q+m+1,cmp);
	solve();
	cout<<ans;
	return 0;
}
