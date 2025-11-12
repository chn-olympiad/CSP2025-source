#include<bits/stdc++.h>//Fail
using namespace std;
const int N=2e4+50,M=2e6+50;
struct Road{
	int u,v;
	long long w;
}r[M],r1[M];
bool cmp(Road a,Road b){
	return a.w<b.w;
}
int tot=0,tot1,fa[N],siz[N];
long long a[15][N],now,ans=1e15;
int find(int x){
	return (fa[x]==x)?(x):(fa[x]=find(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v;long long w;
		scanf("%d %d %lld",&u,&v,&w);
		r[++tot]={u,v,w};
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(j!=0&&a[i][j]==0) a[i][n+1]=1;
		}
		if(a[i][0]!=0||a[i][n+1]!=1) flag=0;
	}
	int cnt;
	for(int s=0,p;s<(1<<k);s++){
		if(flag) s=(1<<k)-1;
		now=0;tot1=0;cnt=n;
		for(int i=1;i<=tot;i++){
			r1[++tot1]=r[i];
		}
		for(int i=1;i<=k;i++){
			if(s&(1<<(i-1))){
				for(int j=1;j<=n;j++){
					r1[++tot1]={i+n,j,a[i][j]};
				}
				now+=a[i][0];
				cnt++;
			}
		}
		sort(r1+1,r1+tot1+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1; 
		for(int i=1;i<=tot1;i++){
			int fu=find(r1[i].u),fv=find(r1[i].v);
	//		printf("%d %d %lld\n",fu,fv,r1[i].w);
			if(fu!=fv){
				if(siz[fu]>siz[fv]) swap(fu,fv);
				siz[fv]+=siz[fu];
				fa[fu]=fv;
				now+=r1[i].w;
				cnt--;
				if(cnt==1) break;
			}
		}
		ans=min(ans,now);	
	}
	printf("%lld\n",ans);
	
	
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/