#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,M=1e4+5,K=11;
int n,m,k,ans,mt;
struct cat{
	int u,v,w;
}e[N],E[M*K],Et[M*K];
int f[N],cnt[K],t[K][M],ansx;
bool cmp(cat xx,cat yy){
	return xx.w<yy.w;
}
int sr;
char c;
int read(){
	sr=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		sr=sr*10+c-'0';
		c=getchar();
	}
	return sr;
}
int find(int x){
	if(f[x]==x)return x;
	else return f[x]=find(f[x]);
}
void dfs(int x,int y){
	if(y>ans)return ;
	if(x>k){
		int ansx=0;
		for(int i=1;i<=mt;i++)E[i]=Et[i];
		sort(E+1,E+mt+1,cmp);
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1,j=1;i<=m||j<=mt;){
			if(j>mt||(i<=m&&e[i].w<E[j].w)){
				int u=e[i].u,v=e[i].v;
				u=find(u);
				v=find(v);
				if(u!=v){
					ansx+=e[i].w;
					f[u]=v;
				}
				i++;
			}
			else{
				int u=E[j].u,v=E[j].v;
				u=find(u);
				v=find(v);
				if(u!=v){
					ansx+=E[j].w;
					f[u]=v;
				}
				j++;
			}
			if(ansx+y>ans)break ;
		}
		ans=min(ans,ansx+y);
		return ;
	}
	int cntv=mt;
	for(int i=1;i<=n;i++)Et[++mt]=cat{n+x,i,t[x][i]};
	dfs(x+1,y+cnt[x]);
	mt=cntv;
	dfs(x+1,y);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int p=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		cin>>cnt[i];
		int pp=0;
		for(int j=1;j<=n;j++)cin>>t[i][j],pp=(pp|(t[i][j]==0));
		p=(p&(pp&&cnt[i]==0));
	}
	if(p){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				e[++m]=cat{n+i,j,t[i][j]};
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		u=find(u);
		v=find(v);
		if(u!=v){
			ans+=e[i].w;
			f[u]=v;
		}
	}
	if(!k||p)cout<<ans;
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4