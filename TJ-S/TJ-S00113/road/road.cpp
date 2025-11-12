#include<bits/stdc++.h>
using namespace std;
const int N=1e4+12,M=1e7+10;
int n,m,k;
int kk[12][N];
int h[N],hh[N],e[M],ne[M],w[M],idx=1;
void add(int a,int b,int c,int hhh[]){
	e[idx]=b,ne[idx]=hhh[a],w[idx]=c,hhh[a]=idx++;
}

int num[11];
int ans=1e9;
void dfs(int u){
	if(u>k){
		int res=0;
		int tt=n;
		int dist[N]{0},st[N]{0};
		memcpy(hh,h,sizeof h);
		for(int i=1;i<=k;i++){
			if(num[i]){
				tt++;
				for(int j=1;j<=n;j++){
					add(i+n,j,kk[i][j],hh);
					add(j,i+n,kk[i][j],hh);
				}
				res+=kk[i][0];
			}
		}
		if(res>ans)return;
		int pp=0;
		memset(dist,0x3f,sizeof dist);
		dist[1]=0;
		for(int i=1;i<=tt;i++){
			int t=-1;
			for(int j=1;j<=tt;j++)if(st[j]==0&&(t==-1||dist[t]>dist[j])){
				t=j;
			}
			if(t<=n)pp++;
			res+=dist[t];
			if(res>ans||dist[t]>=0x3f3f3f3f/2||res>=0x3f3f3f3f/2){
				return;
			}
			dist[t]=0;
			st[t]=1;
			if(pp==n)break;
			for(int j=hh[t];j;j=ne[j]){
				int qqq=e[j];
				dist[qqq]=min(dist[qqq],w[j]);
			}
		}
		ans=min(ans,res);
	}
	else{
		num[u]=0;
		dfs(u+1);
		num[u]=1;
		dfs(u+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		add(a,b,w,h);
		add(b,a,w,h);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)scanf("%d",&kk[i][j]);
	}
	dfs(1);
	printf("%d",ans); 
	return 0;
} 
