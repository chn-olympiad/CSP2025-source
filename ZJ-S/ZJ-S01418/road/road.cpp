#include<bits/stdc++.h>
#define ll long long
//#define bc __builtin_popcount()
#define pr pair<int,int>
#define prr pair<ll,pr>
#define fi first
#define se second
#define N 10005
#define M 1000005
using namespace std;
int n,m,k;
ll c[15],fa[M<<1];
prr ea[M],tmp[M<<1],uu[M<<1],vv[N];
prr e[15][N];
void sortt(int x,int y){
	ll l=1,r=1,t=1;
	while(l<=x&&r<=y){
		if(uu[l].fi>vv[r].fi)tmp[t++]=vv[r++];
		else tmp[t++]=uu[l++];
	}
	while(l<=x)tmp[t++]=uu[l++];
	while(r<=y)tmp[t++]=vv[r++];
	return;
}
int sorts(int x){
	int sz=m,szz=n+1,tmptmp=0;
	for(int i=1;i<=m;i++)tmp[i]=ea[i];
	for(int i=1;i<=k;i++)if((1<<i-1)&x){
		for(int j=1;j<=sz;j++)uu[j]=tmp[j];
		for(int j=1;j<=n;j++)vv[j]=e[i][j],vv[j].se.se=szz;//cout<<"&&";
		sortt(sz,n);//cout<<"^^";
		sz+=n,szz++,tmptmp++;
	}
	return tmptmp;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
ll solve(int x){
	int tmptmp=sorts(x);
	int sz=m+n*tmptmp,szz=n+tmptmp;
	for(int i=1;i<=szz;i++)fa[i]=i;
	ll ans=0;
	for(int i=1;i<=k;i++)if((1<<i-1)&x)ans+=c[i];
	int cnt=0;
	for(int i=1;i<=sz&&cnt<szz;i++){
		int u=find(tmp[i].se.fi),v=find(tmp[i].se.se);
		if(u!=v){
			ans+=tmp[i].fi;
			fa[u]=v;
			cnt++;
		}
	}//cout<<cnt<<"\n";
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>ea[i].se.fi>>ea[i].se.se>>ea[i].fi;
	sort(ea+1,ea+m+1);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>e[i][j].fi,e[i][j].se.fi=j,e[i][j].se.se=n+i;
		sort(e[i]+1,e[i]+n+1);
	}
	int zk=(1<<k);
	ll ans=10000000000000007ll;
	for(int i=zk-1;i>=0;i--)ans=min(ans,solve(i));
	cout<<ans;
	return 0;
}
