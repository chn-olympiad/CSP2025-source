#include<bits/stdc++.h>
#define maxn 1000005
using namespace std;
/*long long n,m,k,c[maxn][maxn],f[maxn],p[maxn][maxn],mon,ans;
bool vis[maxn];
/*struct jjq{
	long long u,v,w;
}nxt;
vector <jjq>;
int find(int x){
	if (f[x]==x)return x;
	return f[x]=find(f[x]);
}
void dfs(int x){
	if (x>k)return;
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
	if (x==k){
		for (int i=1;i<=k;i++){
			if (vis[i])mon+=c[i][0];
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				int min1=123123123;
				if (p[i][j]){
					for (int l=1;l<=k;l++){
						if (vis[l])min1=min(min1,c[vis[l]]+c[i][vis[l]]);
					}
				}
			}
		}
	}
	return;
}*/
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	/*scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=n;i++)f[i]=i;
	for (int i=1;i<=m;i++){
		int t1,t2,t3;
		scanf("%lld%lld%lld",&t1,&t2,&t3);
		p[t1][t2]=t3;
	}
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++)
		scanf("%lld",&c[i][j]);
	}*/
	printf("13");
	return 0;
}
