#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,k;
struct road{
	ll u,v,w;
}b[2000010];
ll d[1010][1010];
ll c[15],a[15][10010];
ll leader[10010];
bool cmp(road a,road b){
	if(a.w<b.w)return 1;
	else return 0;
}
ll find(ll x){
	if(leader[x]==x)return x;
	else return find(leader[x]);
}
ll check(ll x,ll y){
	if(find(x)!=find(y))return 0;
	else return 1;
}
ll con(ll x,ll y){
	leader[find(y)]=find(x);
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
		if(b[i].u>b[i].v)swap(b[i].u,b[i].v);
	}
	ll flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}	
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)leader[i]=i;
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(!check(b[i].u,b[i].v)){
			con(b[i].u,b[i].v);
			ans+=b[i].w;
		}
	}
	if(flag||k==0){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ll temp=1e9+7;
			for(int t=1;t<=k;t++){
				temp=min(temp,a[t][i]+a[t][j]);
			}
			b[++m].u=i;
			b[m].v=j;
			b[m].w=temp;
		}
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)leader[i]=i;
	ans=0;
	for(int i=1;i<=m;i++){
		if(!check(b[i].u,b[i].v)){
			con(b[i].u,b[i].v);
			ans+=b[i].w;
		}
	}
	cout<<ans;
	return 0;
}
