#include<bits/stdc++.h>
#define ri register long long
#define int long long
#define rll register long long
#define ll long long
#define pint pair<int,int>
#define endl '\n'
using namespace std;
const ll N=2e4+5,M=2e6+5;
const ll inf=1e18;
ll n,m,k,top;
ll fa[N],cost[15],f[15];
int flag[15];
ll num[15];
struct edge{
	ll u,v,w,id;
}e[M<<1];
inline bool cmp(edge a,edge b){
	return a.w<b.w;
}
inline ll find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(rll i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,e[i].id=0,top++;
	for(rll i=1;i<=k;i++){
		cin>>cost[i];
		f[i]=f[i-1]+cost[i];
		for(rll j=1;j<=n;j++){
			top++;
			cin>>e[top].w;
			e[top].u=j; 
			e[top].v=n+i; 
			e[top].id=i; 
		}
	}
	sort(e+1,e+1+top,cmp);
	ll tans=inf;
	for(ri i=0;i<=k;i++){
		for(ri j=1;j<=n+k;j++)fa[j]=j;
		for(ri i=1;i<=k;i++)num[i]=flag[i]=0;
		ll ans=0;
		for(ri j=1;j<=top;j++){
			if(e[j].id>i)continue;
			int x=e[j].u,y=e[j].v,z=e[j].w;
			int fx=find(x),fy=find(y);
			if(fx!=fy){
				if(y>n){
					if(!flag[y-n])flag[y-n]=1,num[y-n]=z;
					else if(flag[y-n]==1)flag[y-n]=2,ans+=num[y-n]+z+cost[y-n];
					else ans+=z;
				}
				else ans+=z;
				fa[fx]=fy;
			}
		}
		tans=min(tans,ans);
	}
	cout<<tans<<endl;
	return 0;
}
