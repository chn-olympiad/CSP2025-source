#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,K=15,M=1e6+10;
const long long INF=1e18;
int a[K][N];
int c[K];
struct edge{
	int u,v,w;
} e[2*M];
bool is[K];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	long long ans=INF;
	sort(e+1,e+m+1,cmp);
	for(int i=m;i>=1;i--){
		bool flag=0;
		for(int j=1;j<=k;j++){
			if(a[j][e[i].u]+a[j][e[i].v]+c[j]<e[i].w){
				m--;
				flag=1;
//				cout<<m<<"\n";
				break;
			}
		}
		if(!flag) break;
	}
	for(int cur=0;cur<(1<<k);cur++){
		long long tmp=0;
		int cnt=0;
		for(int i=1;i<=k;i++){
			if(cur &(1<<(i-1))) is[i]=1;
			else is[i]=0;
		}
		int add=0;
		for(int i=1;i<=k;i++){
			if(is[i]){
				add++;
				tmp+=c[i];//加上建造费用
				for(int j=1;j<=n;j++){
					cnt++;
					e[m+cnt]={n+add,j,a[i][j]};
				}
			}
		}
		for(int i=1;i<=n+add;i++){
			fa[i]=i;
		}
		sort(e+m+1,e+m+cnt+1,cmp);//!
		int i=1,j=1;
		int tot=n+add;
		for(i;i+j<=m+cnt;){
			if((e[i].w<e[m+j].w && i<m) || j>=cnt){
				int qx=find(e[i].u),qy=find(e[i].v);
				if(qx!=qy){
					fa[qx]=qy;
					tmp+=e[i].w;
					tot--;
				}
				i++;
			}else{
				int qx=find(e[m+j].u),qy=find(e[m+j].v);
				if(qx!=qy){
					fa[qx]=qy;
					tmp+=e[m+j].w;
					tot--;
				}
				j++;
			}
			if(tot==1){
				break;
			}
		}
//		cout<<tmp<<"\n";
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}
