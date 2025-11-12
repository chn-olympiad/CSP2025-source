#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,k,ans=LLONG_MAX,sss;
ll c[11];
ll ww[11][10014];
bool ff[11];
struct node{
	ll u;
	ll v;
	ll w;
}a[1200006];
node b[1200006];
bool vis[10014];
bool cmp(node x,node y){
	return x.w<y.w;
}
void solve1(){
	ll sum=0;
	ll cnt=0;
	for(ll i=1;i<=m+sss;++i){
		b[i]=a[i];
	}
	sort(b+1,b+1+m+sss,cmp);
	memset(vis,0,sizeof(vis));
	for(ll i=1;i<=k;i++){
		if(ff[i]==1) sum+=c[i];
	}
	for(ll i=1;i<=m+sss;++i){
//		cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
		if(cnt==n) break;
		if(vis[b[i].u]==1&&vis[b[i].v]==1) continue;
		if(vis[b[i].u]==0){
			vis[b[i].u]=1;
			if(b[i].u<=n) cnt++;
		}
		if(vis[b[i].v]==0){
			vis[b[i].v]=1;
			if(b[i].v<=n) cnt++;
		}
		sum+=b[i].w;
		if(sum>ans) break;
	}
//	cout<<sum<<" ";
	ans=min(ans,sum);
	return ;
}
void dfs(ll d){
	if(d==k){
		solve1();
		return ;
	}
	
	d++;
	dfs(d);
	
	ff[d]=1;
	for(ll j=1;j<=n;++j){
		sss++;
		a[m+sss].u=j;
		a[m+sss].v=n+d;
		a[m+sss].w=ww[d][j];
	}
	dfs(d);
	sss-=n;
	ff[d]=0;
	
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(ll i=1;i<=m;++i){
		ll u,v,w;
		cin>>u>>v>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	if(k==0){
		sss=0;
		solve1();
		cout<<ans;
		return 0;
	}
	bool f=0,f1=0;
	for(ll i=1;i<=k;++i){
		cin>>c[i];
		if(c[i]!=0) f=1;
		for(ll j=1;j<=n;++j){
			cin>>ww[i][j];
			if(ww[i][j]!=0) f1=0;
		}
	}
	if(f==0&&f1==0){
		cout<<"0";
		return 0;
	}
	if(f==0){
		sss=n*k;
		for(ll i=1;i<=k;++i){
			for(ll j=1;j<=n;++j){
				a[m+(i-1)*n+j].u=j;
				a[m+(i-1)*n+j].v=n+i;
				a[m+(i-1)*n+j].w=ww[i][j];
			}
		}
		solve1();
		cout<<ans;
		return 0;
	}
	dfs(0);
	cout<<ans;
	return 0;
}
