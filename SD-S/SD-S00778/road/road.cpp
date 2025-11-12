#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e7+5;
int r[N],c[N];
long long a[15][N];
int F[N][N];
__int128 ans=0x7fffffffffffffff;
int n,m,k;
struct node{
	int u,v;
	long long w;
}g[M];
void print(__int128 n){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n<=9){
		putchar(n+'0');
		return ;
	}
	else{
		print(n/10);
		putchar(n%10+'0');
		return ;
	}
}
bool cmp(node x,node y){
	return x.w<y.w;
}
void func(){
	for(int i=1;i<=n;i++){
		r[i]=i;
	}
	return ;
}
int f(int x){
	if(r[x]!=x){
		r[x]=f(r[x]);
	}
	return r[x];
}
void merge(int x,int y){
	int X=f(x);
	int Y=f(y);
	if(X!=Y){
		r[X]=Y;
	}
	return ;
}
node t[M];
int vis[15];
void dfs(int u){
	if(u>k){
		func();
		long long nw=m;
		__int128 sum=0;
		for(int i=1;i<=m;i++){
			t[i].u=g[i].u;
			t[i].v=g[i].v;
			t[i].w=g[i].w;
		}
		//³õÊ¼»¯ 
		for(int i=1;i<=k;i++){
			if(vis[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++){
					for(int q=j+1;q<=n;q++){
						if(F[j][q]&&F[j][q]<a[i][j]+a[i][q]) continue;
						nw++;
						t[nw].u=j;
						t[nw].v=q;
						t[nw].w=a[i][j]+a[i][q];
					}
				}
			}
		}
		sort(t+1,t+nw+1,cmp);
		for(int i=1;i<=nw;i++){
			if(f(t[i].u)!=f(t[i].v)){
				merge(t[i].u,t[i].v);sum+=t[i].w;
			}
		}
		ans=min(ans,sum);
		return ;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&g[i].u,&g[i].v,&g[i].w);
		F[g[i].u][g[i].v]=g[i].w;
		F[g[i].v][g[i].u]=g[i].w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]) flag=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j])flag=0;
		}
	}
	if(flag&&k){
		printf("0");
		return 0;
	}
	else dfs(1);
	print(ans);
	return 0;
}

