#include<bits/stdc++.h>
#define N 10005
#define M 1000005
using namespace std;
struct E{
	int u,v,w;
}e[M<<1],t[N<<4],q[N<<4];
int n,m,k,u,v,w,cnt,fa[N];
long long ans=1e18;
int edge[1][N+15],f[15];
int W[15],g[15][N];
inline int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}inline void merge(int x,int y){
	fa[find(x)]=find(y);
}int cmp(E a,E b){
	return a.w<b.w;
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,cnt++;
	for(int i=1;i<=k;i++){
		cin>>W[i];
		for(int j=1;j<=n;j++)cin>>g[i][j];
	}
/*	for(int i=1;i<=k;i++){
		cin>>w,sum[i]=sum[i-1]+w;
		for(int j=1;j<=n;j++)cin>>w,e[++cnt]={n+i,j,w};
	}sort(e+1,e+cnt+1,cmp);
	for(int i=0;i<=k;i++){
		long long tmp=0;
		for(int j=1;j<=n+i;j++)fa[j]=j;
		for(int j=1,chosen=0;j<=cnt;j++){
			int u=e[j].u,v=e[j].v,w=e[j].w;
			if(find(u)!=find(v)){
				merge(u,v),chosen++,tmp+=w;
				if(chosen==n+i-1)break;
			}
		}cout<<tmp<<endl;
		ans=min(ans,tmp+sum[i]);
	}cout<<ans<<endl;*/
	sort(e+1,e+cnt+1,cmp);
	for(int j=1;j<=n;j++)fa[j]=j;
	int tmp=0;
	for(int j=1,chosen=0;j<=cnt;j++){
		int u=e[j].u,v=e[j].v;
		if(find(u)!=find(v)){
			merge(u,v),chosen++;
			edge[0][chosen]=j;
			if(chosen==n-1)break;
		}
}for(int i=1;i<n;i++){
			int k=edge[0][i];
			t[++tmp]={e[k].u,e[k].v,e[k].w};
		}
		for(int i=1;i<=k;i++)
		{
			
			for(int j=1;j<=n;j++)t[++tmp]={n+i,j,g[i][j]};
		}
	sort(t+1,t+tmp+1,cmp);
	for(int s=0;s<1<<k;s++){
		memset(f,0,sizeof f);
		int tt=s,tot=0;
		long long sum=0;
		while(tt)f[++tot]=tt&1,tt>>=1;
		int g1=0;
		for(int i=1;i<=tot;i++)if(f[i])sum+=W[i],g1++;
		/*
		for(int i=1;i<n;i++){
			int k=edge[0][i];
			t[++tmp]={e[k].u,e[k].v,e[k].w};
		}for(int i=1;i<=k;i++)
		if(f[i]){
			sum+=W[i],g1++;
			for(int j=1;j<=n;j++)t[++tmp]={n+i,j,g[i][j]};
		}sort(t+1,t+tmp+1,cmp);*/
		int jjj=0;
		for(int i=1;i<=tmp;i++){
			if(t[i].u<=n||f[t[i].u-n])q[++jjj]=t[i];
		}long long tmq=0;
		for(int j=1;j<=n+10;j++)fa[j]=j;
		for(int j=1,chosen=0;j<=jjj;j++){int u=q[j].u,v=q[j].v;
		if(find(u)!=find(v)){
			merge(u,v),chosen++,tmq+=q[j].w;
			if(chosen==n+g1-1)break;
		}}ans=min(ans,tmq+sum);
	}cout<<ans<<endl;
	return 0;
}/*
luogu:sms123
orz kkksc03,chen_zhe,Alex_Wei...

IIIIIIIIII          WW      WW     IIIIIIIIII     LL             LL        
    II              WW      WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WW  WW  WW         II         LL             LL
    II              WWWW  WWWW         II         LL             LL
IIIIIIIIII          WW      WW     IIIIIIIIII     LLLLLLLLLL     LLLLLLLLLL


    AA         KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!
  AA  AA       KK    KK                II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AA      AA     KKKK                    II         OO      OO         II         !!
AA      AA     KK  KK                  II         OO      OO         II         !!
AAAAAAAAAA     KK    KK                II         OO      OO         II
AA      AA     KK      KK          IIIIIIIIII       OOOOOO       IIIIIIIIII     !!


RRRRRRRR       PPPPPPPP
RR      RR     PP      PP         ++             ++
RR      RR     PP      PP         ++             ++
RRRRRRRR       PPPPPPPP       ++++++++++     ++++++++++
RR  RR         PP                 ++             ++
RR    RR       PP                 ++             ++
RR      RR     PP

long long int rp = 0;
int main()
{
	while (1) rp++;
	return 0;
}

PLEASE DO NOT
//freopen
feropen
freeopen
freopen("",r,stdin);
freopen("","r",stdout);
freopen("","r",stdin);
*/