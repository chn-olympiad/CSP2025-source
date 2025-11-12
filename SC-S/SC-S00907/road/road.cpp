#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int N=1e4+6;
const int M=1e6+6;
int n,m,k,fa[N];
ll mp[1005][1005];
int c[15];
ll a[15][N];
struct edge{
	ll u,v,w;
	bool operator <(const edge &x){
		return w<x.w;
	}
}ee[M],tmp[M];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
bool check(){
	for(int i=1;i<=k;i++){
		if(c[i])return 0;
	}
	return 1;
}
ll calc(vector<int>id){
	ll ans=0;
	if(!id.empty())for(int i:id)ans+=c[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)mp[j][i]=mp[i][j]=1e12;
	}
	for(int i=1;i<=m;i++)ee[i]=tmp[i];
	for(int i=1;i<=m;i++){
		mp[ee[i].u][ee[i].v]=min(mp[ee[i].u][ee[i].v],ee[i].w);
	}
	for(int i=1;i<=n;i++)mp[i][i]=0;
	if(!id.empty())for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l:id){
				mp[j][i]=mp[i][j]=min(min(mp[j][i],mp[i][j]),a[l][i]+a[l][j]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ee[++cnt].u=i;
			ee[cnt].v=j;
			ee[cnt].w=min(mp[j][i],mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ee+1,ee+cnt+1);
	int tot=0;
	for(int i=1;i<=m;i++){
		int u=find(ee[i].u);
		int v=find(ee[i].v);
		if(u==v)continue;
		++tot;
		fa[u]=v;
		ans+=ee[i].w;
		if(tot==n-1)break;
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int u,v,w,i=1;i<=m;i++){
		u=read();v=read();w=read();
		ee[i].u=u;
		ee[i].v=v;
		ee[i].w=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	ll ans=0;
	if(k==0){
		sort(ee+1,ee+m+1);
		int cnt=0;
		for(int i=1;i<=m;i++){
			int u=find(ee[i].u);
			int v=find(ee[i].v);
			if(u==v)continue;
			++cnt;
			fa[u]=v;
			ans+=ee[i].w;
			if(cnt==n-1)break;
		}
		write(ans);
		return 0;
	}
	if(check()){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)mp[i][j]=1e12;
		}
		for(int i=1;i<=m;i++){
			mp[ee[i].u][ee[i].v]=min(mp[ee[i].u][ee[i].v],ee[i].w);
		}
		for(int i=1;i<=n;i++)mp[i][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=k;l++){
					mp[j][i]=mp[i][j]=min(min(mp[j][i],mp[i][j]),a[l][i]+a[l][j]);
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ee[++cnt].u=i;
				ee[cnt].v=j;
				ee[cnt].w=mp[i][j];
			}
		}
		sort(ee+1,ee+cnt+1);
		int tot=0;
		for(int i=1;i<=m;i++){
			int u=find(ee[i].u);
			int v=find(ee[i].v);
			if(u==v)continue;
			++tot;
			fa[u]=v;
			ans+=ee[i].w;
			if(tot==n-1)break;
		}
		write(ans);
		return 0;
	}
	for(int i=1;i<=m;i++)tmp[i]=ee[i];
	ans=LLONG_MAX;
	for(int S=0;S<1<<k;S++){
		vector<int>id;
		for(int i=1;i<=k;i++){
			if(S&(1<<(i-1)))id.emplace_back(i);
			ans=min(ans,calc(id));
		}
	}
	write(ans);
	return 0;
}