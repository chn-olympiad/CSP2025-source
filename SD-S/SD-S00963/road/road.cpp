#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n,m,k;
struct edge{
	int u,v;
	ll w;
	int id;
}a[M];
int flaga,flagaa;
ll c[15],ans,dis[1005][1005],b[15][N];
int fa[M],flag[15],cnt;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int Find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=Find(fa[x]);
}
void merge(int x,int y){
	int fx=Find(x),fy=Find(y);
	if(fx!=fy)fa[fx]=fy;
}
void check(){	
	ll sum=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;	
	}
//	for(int i=1;i<=k;i++){
//		if(flag[i])sum+=c[i]; 
//		cout<<flag[i]<<" ";
//	}
//	cout<<sum;
//	cout<<"\n";
	for(int i=1;i<=cnt;i++){
//		if(!flag[a[i].id])continue;
		int u=a[i].u;
		int v=a[i].v;
		int fu=Find(u),fv=Find(v);
		if(fu!=fv){
			fa[fu]=fv;
			sum+=a[i].w;
		}
	}
//	cout<<sum<<"\n";
	ans=min(ans,sum);
}
void check2(){	
	ll sum=0;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;	
	}
	for(int i=1;i<=k;i++){
		if(flag[i])sum+=c[i]; 
//		cout<<flag[i]<<" ";
	}
//	cout<<sum;
//	cout<<"\n";
	for(int i=1;i<=cnt;i++){
		if(!flag[a[i].id])continue;
		int u=a[i].u;
		int v=a[i].v;
		int fu=Find(u),fv=Find(v);
		if(fu!=fv){
			fa[fu]=fv;
			sum+=a[i].w;
		}
	}
//	cout<<sum<<"\n";
	ans=min(ans,sum);
}
void dfs(int s){
	if(s==k+1){
		check2();
		return ;
	}
	flag[s]=1;
	dfs(s+1);
	flag[s]=0;
	dfs(s+1);
	flag[s]=0;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].id=0;
	}
	flag[0]=1;
	cnt=m;
//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++){
//			cin>>b[i][j];
//		}
//	} 
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int p=1;p<=k;p++){
//				dis[i][j]=min(dis[i][j],dis[p][j]+dis[p][i]);
//			}
//		}
//	}
//	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flaga=1;
		flagaa=0;
		for(int j=1;j<=n;j++){
			cnt++;
			cin>>a[cnt].w;
			if(a[cnt].w==0)flagaa=1;
			a[cnt].u=i+n;
			a[cnt].v=j;
			a[cnt].id=i;
		}
		if(flagaa==0)flaga=1;
	}
	sort(a+1,a+1+cnt,cmp);
	ans=INF;
	if(k==0){
		check();
		cout<<ans;
		return 0;
	}	
//	dfs(1);
	if(flaga==0){
		check();
		cout<<ans;
		return 0;		
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/


//-g3
