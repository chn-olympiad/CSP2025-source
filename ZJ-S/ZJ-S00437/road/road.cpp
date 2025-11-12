//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5,N=1e4+5;
int n,m,k,cnt,a[15][10005],c[15],fa[N],hd[N];
struct edge{
	int u,v,w,nxt;
}e[M*2+N*10];
inline void add_edge(int u,int v,int w){
	e[++cnt]=edge{u,v,w,hd[u]};
	hd[u]=cnt;
}
bool cmp(edge X,edge Y){
	return X.w<Y.w;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
inline int MST(int res){
	sort(e+1,e+cnt+1,cmp);
	int ans=0,ed=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;ed<n+res-1;i++){
		int u=e[i].u,v=e[i].v;
		int rootu=find(u),rootv=find(v);
		if(rootu!=rootv){
			ans+=e[i].w;
			ed++;
			fa[rootu]=rootv;
		}
	}
	return ans;
}
bool flag;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int ans=-1;
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);	
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i])flag=1;
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
//	cout<<MST(0);
	int sum=0,res=0;
	if(!flag){
		for(int j=0;j<k;j++){
			res++;
			sum+=c[j+1];
			for(int x=1;x<=n;x++){
				add_edge(n+j+1,x,a[j+1][x]);
				add_edge(x,n+j+1,a[j+1][x]);					
			}
		}
		cout<<MST(res)+sum;
		return 0;
	}
	for(int i=0;i<pow(2,k);i++){
		cnt=m*2;
		sum=0,res=0;
		for(int j=0;j<k;j++)
			if((1<<j)&i){
				res++;
				sum+=c[j+1];
				for(int x=1;x<=n;x++){
					add_edge(n+j+1,x,a[j+1][x]);
					add_edge(x,n+j+1,a[j+1][x]);					
				}
			}
//		cout<<cnt<<" "<<MST(res)<<"\n";
		sum+=MST(res);
		if(ans==-1||ans>sum)ans=sum;
	}
	cout<<ans;
	return 0;
}
