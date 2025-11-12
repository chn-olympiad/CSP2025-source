#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
using namespace std;
mt19937_64 rd(time(0));
const ll N=1e5+5;
ll n,ans,yong[15],a[15][N],f[N],m,k,sum;
struct node{
	ll u,v,w;
}Bian[N*10],bian[N*10];
bool cmp(node x,node y){
	return x.w<y.w; 
}
ll find(ll u){
	if(u==f[u])return u;
	return f[u]=find(f[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>Bian[i].u>>Bian[i].v>>Bian[i].w;
	}
	sort(Bian+1,Bian+m+1,cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		ll u=Bian[i].u,v=Bian[i].v;
		ll x=find(u),y=find(v);
		if(sum==n-1)break;
		if(x==y)continue;
		sum++;ans+=Bian[i].w;
		f[x]=y;
		bian[sum].u=u,bian[sum].v=v,bian[sum].w=Bian[i].w;
	}
//	cout<<ans<<endl;
	for(int i=1;i<=k;i++){
		cin>>yong[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}sum=0;
	for(int i=1;i<(1<<k);i++){
		ll cnt=n-1,anss=0;sum=n;
		for(int j=1;j<n;j++)Bian[j].u=bian[j].u,Bian[j].v=bian[j].v,Bian[j].w=bian[j].w;
		for(int j=1;j<=k;j++){
			if((i>>(j-1))&1){
				sum++;anss+=yong[j];
				for(int l=1;l<=n;l++){
					bian[++cnt].u=sum;bian[cnt].v=l,bian[cnt].w=a[j][l];
				}
			}
		}
		if(anss<ans){
			for(int j=1;j<=sum;j++)f[j]=j;
			sort(bian+1,bian+cnt+1,cmp);
			ll now=0;
			for(int j=1;j<=cnt;j++){
				if(now==sum-1)break;
				ll u=bian[j].u,v=bian[j].v;
				ll x=find(u),y=find(v);
				if(x==y)continue;
				now++;anss+=bian[j].w;
				if(anss>=ans)break;
				f[x]=y;
			}
			ans=min(ans,anss);
			//if(ans==5){cout<<i<<endl;}
		}
		for(int j=1;j<n;j++)bian[j].u=Bian[j].u,bian[j].v=Bian[j].v,bian[j].w=Bian[j].w;
	}
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%

