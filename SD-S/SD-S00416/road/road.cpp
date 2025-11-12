#include<bits/stdc++.h>
using namespace std;
const int N=1e5+15,M=1e6+5;

#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define FORG(i,u) for(int i=head[u];~i;i=nxt[i])
struct mmap{
	int x,y,w;
}mat[M],jia[M];
int fa[N];
int c[N],a[15][N];
int n,m,k;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int cnt;
int kusk(){
	FOR(i,1,n+10)fa[i]=i;
	int p=1;int res=0;
	for(int i=1;i<=m;i++){
		for(;p<=cnt&&jia[p].w<mat[i].w;p++){
			int x=find(jia[p].x),y=find(jia[p].y);
			if(x!=y){
				fa[x]=y;
				res+=jia[p].w;
			}
		}
		int x=find(mat[i].x),y=find(mat[i].y);
		if(x!=y){
			fa[x]=y;
			res+=mat[i].w;
		}
	}
	return res;
}
bool cmp(mmap x,mmap y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	FOR(i,1,m){
		cin>>mat[i].x>>mat[i].y>>mat[i].w;
	}
	bool flag=1;
	FOR(i,1,k){
		cin>>c[i];
		FOR(j,1,n){
			cin>>a[i][j];
			if(a[i][j])flag=0;
		}
		if(c[i])flag=0;
	}
	sort(mat+1,mat+m+1,cmp);
	if(flag){
		FOR(i,1,k){
			for(int p=1;p<=n;p++){
				jia[++cnt]={n+i,p,a[i][p]};
			}
		}
		sort(jia+1,jia+cnt+1,cmp);
		cout<<kusk();
		return 0;
	}
	int ans=LONG_LONG_MAX;
	FOR(i,0,(1<<k)-1){
		cnt=0;
		int res=0;int totnum=0;
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i){
				totnum++;
				for(int p=1;p<=n;p++){
					jia[++cnt]={n+totnum,p,a[j][p]};
				}
				res+=c[j];
			}
		}
		sort(jia+1,jia+cnt+1,cmp);
		ans=min(ans,kusk()+res);
	}
	cout<<ans;
	return 0;
} 
