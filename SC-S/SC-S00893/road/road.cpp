#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e4+5,M=3e6+5,K=15,P=2e4+5;
struct node{int x,y,z;}a[M],b[M];
int c[K],num[K][N];bool vis[K];
int n,m,k;int fa[P];ll minn=1e17;
struct edge{int num,id;}w[K];
int maxtim,nowtim;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<3)+(s<<1)+(ch^48),ch=getchar();}
	return s*f;
}

inline bool operator < (node x,node y){
	return x.z<y.z;
} 

inline bool operator < (edge x,edge y){
	return x.num<y.num;
}

inline int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

inline void kruskal(int nx,int mx,int pre){
	for(int i=1;i<=mx;i++) b[i]=a[i];
	for(int i=1;i<=nx;i++) fa[i]=i;
	sort(b+1,b+mx+1);
	ll ans=pre;
	for(int i=1;i<=mx;i++){
		int x=b[i].x,y=b[i].y,z=b[i].z;
		int rx=get(x),ry=get(y);
		if(rx==ry) continue;
		ans+=z;fa[rx]=ry;
	}
	minn=min(minn,ans);
}

inline void dfs(int step,int sum){
	if(step==k+1){
		int mx=m,nx=n;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				nx++;
				for(int j=1;j<=n;j++) a[++mx]={nx,j,num[i][j]}; 
			}
		} 
		kruskal(nx,mx,sum);
		return;
	}
	vis[step]=1;
	dfs(step+1,sum+c[step]);
	vis[step]=0;
	dfs(step+1,sum);
}

inline void dfss(int step,int sum){
	if(step==k+1){
		int mx=m,nx=n;
		for(int i=1;i<=k;i++){
			if(vis[i]){
				nx++;
				for(int j=1;j<=n;j++) a[++mx]={nx,j,num[i][j]}; 
			}
		} 
		kruskal(nx,mx,sum);
		nowtim++;
		if(nowtim>maxtim){
			cout<<minn;
			exit(0);
		}
		return;
	}
	if(step&1){
		vis[w[step].id]=1;
		dfss(step+1,sum+c[w[step].id]);
		vis[w[step].id]=0;
		dfss(step+1,sum);
	}else{
		vis[w[step].id]=1;
		dfss(step+1,sum+c[w[step].id]);
		vis[w[step].id]=0;
		dfss(step+1,sum);
	}	
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) a[i]={read(),read(),read()};
	bool tag=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) num[i][j]=read();
		if(c[i]!=0) tag=0;
		int numx=0;
		for(int j=1;j<=n;j++) 	
			if(num[i][j]==0) numx++;
		if(numx==0) tag=0;
	}
	if(tag==1){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++) a[++m]={n+i,j,num[i][j]}; 
		n+=k;
		kruskal(n,m,0);
		cout<<minn;
	}else if((1ll*(1<<k)*(m*log(m)))<=8e7){
		dfs(1,0);
		cout<<minn;
	}else{
		for(int i=1;i<=k;i++){
			w[i].num=c[i];w[k].id=i;
			for(int j=1;j<=n;j++) w[i].num+=num[i][j];
		}
		sort(w+1,w+k+1);
		maxtim=8e7/(m*log(m));
		dfss(1,0);
	}
	return 0;
}
/*
最小生成树？
看起来就是直接建边，然后此处存在乡村的点权

具体的乡村可以O(2^k)枚举，看起来是可以过32的 
如果一个乡村我开了不去连接他，我为什么要开
所以开了的必须也要联通，完全是最小生成树 
开long long
题好像比较难，感觉可以准备开拼了 

A性质还有24
56了 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/