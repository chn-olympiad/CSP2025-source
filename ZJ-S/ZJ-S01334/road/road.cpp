#include<bits/stdc++.h>
#define int long long
#define N 10005
#define M 2000005
using namespace std;
int n,m,k,c[15],a[15][N],fa[N];
struct edge{
	int dis,bf,to;
}e[M];
int cnt1;
void add(int x,int y,int z){
	e[++cnt1].dis=z;
	e[cnt1].bf=x;
	e[cnt1].to=y;
}
struct node{
	int no,di;
	bool operator<(const node &u)const{
		return di<u.di;
	}
}g[M],gg[M];
int cnt;
int f(int x){
	return fa[x]==x?x:fa[x]=f(fa[x]);
}
int len;
int ff(){
	sort(gg,gg+len+1);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int sum=0,ans=0;
	for(int i=1;i<=len;i++){
		int x=e[gg[i].no].bf,y=e[gg[i].no].to;
		if(f(x)!=f(y)){
			fa[f(x)]=f(y);
			ans+=e[gg[i].no].dis;
			sum+=1;
		}
		if(sum==len-1)break;
	}
	return ans;
}
void solve(){
	int sum=0,ans=INT_MAX;
	for(int i=0;i<(1ll<<k);i++){
		memcpy(gg,g,sizeof g);
		len=m;
		sum=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				for(int l=1;l<=n;l++)
					gg[++len]={m+(j-1)*n+l,e[m+(j-1)*n+l].dis};
				sum+=c[j];
			}
		}
		ans=min(ff()+sum,ans);
	}
	cout<<ans;
}
signed main(){
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	scanf("%lld%lld%lld",&n,&m,&k);
 	for(int i=1,x,y,z;i<=m;i++){
 		scanf("%lld%lld%lld",&x,&y,&z);
 		add(x,y,z);
 		g[++cnt]={cnt1,e[cnt1].dis};
	}
	ff();
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			add(n+i,j,a[i][j]);
		}
	}
	solve();
}