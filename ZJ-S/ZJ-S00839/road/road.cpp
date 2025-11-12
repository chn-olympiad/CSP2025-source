#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10,K=11;
inline int read(){
	int x=0;char c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int n,m,k;

struct road{
	int u,v,w,used;
}edge[M+N*K];
bool cmp1(road x,road y){
	return x.w<y.w;
}
int Cnt=0;
void add(int u,int v,int w,int used){
	edge[++Cnt]={u,v,w,used};
}
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	else {
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
long long solve1(int us){
	long long ans=0,cnt=0;
	for(int i=1;i<=n+us;i++)fa[i]=i;
	for(int i=1;i<=Cnt&&cnt<n+us;i++){
		if(edge[i].used==0)continue;
		int u=find(edge[i].u),v=find(edge[i].v);
		if(u==v)continue;
		fa[u]=v;
		ans+=edge[i].w;
		cnt++;
	}
	return ans;
}

int a[K][N];
int c[K];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		add(u,v,w,1);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			add(n+i,j,a[i][j],0);
		}                
	} 
	
	
	
	sort(edge+1,edge+Cnt+1,cmp1);
	long long ans=1e18;
	for(int us=0;us<(1<<k);us++){
		int cnt1=0,cntc=0;
		for(int i=1;i<=k;i++){
			if(us&(1<<i-1))cnt1++,cntc+=c[i];
		}
		for(int i=1;i<=Cnt;i++){
			road e=edge[i];
			if(e.u>n&&(us&(1<<e.u-n-1))==0)edge[i].used=0;
			else edge[i].used=1;
		}
		ans=min(ans,solve1(cnt1)+cntc);
	}
	printf("%d\n",ans);
	return 0;
}
