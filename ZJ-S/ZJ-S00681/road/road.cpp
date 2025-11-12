#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+10,N=2e4+10;
int f[N],mi,mm,ans,sum,n,m,k,pd[N],c[N];
struct no{int u,v,w;}e[M],ee[M];
bool cmp(no a,no b){return a.w<b.w;}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void yu(){
	int cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		int fx=find(x),fy=find(y);
		if(fx==fy)continue;
		e[++cnt]=e[i],f[fx]=fy,mi+=e[i].w;
		if(cnt==n-1){
			m=cnt;return;
		}
	}
}
void ljx(int x,int y,int z){
	int fx=find(x),fy=find(y);
	if(fx!=fy)f[fx]=fy,sum++,ans+=z;
	return ;
}
void sc(int x,int cnt,int co){
	if(x==n+k+1){
		sum=0;ans=co;
		for(int i=1;i<=n+k;i++)f[i]=i;
		int l=1,r=1;
		while(l<=m||r<=mm){
			if(r>mm)ljx(e[l].u,e[l].v,e[l].w),++l;
			else{
				if(pd[ee[r].u]==0){++r;continue;}
				if(e[l].w<ee[r].w)ljx(e[l].u,e[l].v,e[l].w),++l;
				else ljx(ee[r].u,ee[r].v,ee[r].w),++r;
			}
			if(sum==n+cnt-1){
				mi=min(mi,ans);
				return;
			}
		}
	}
	pd[x]=0,sc(x+1,cnt,co);
	pd[x]=1,sc(x+1,cnt+1,co+c[x-n]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	yu();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			ee[++mm]=(no){i+n,j,x};
		}
	}
	sort(ee+1,ee+1+mm,cmp);
	sc(n+1,0,0);
	cout<<mi;
}