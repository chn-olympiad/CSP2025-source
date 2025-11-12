#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000010,M=1000010;
long long n,m,k,h[N],e[M],ne[M],w[M],idx,a[N];
long long ans=0x3f3f3f3f,res;
bool st[M];
void add(int a,int b,long long c){
	e[idx]=b,w[idx]=min(c,w[idx]),ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u){
	st[u]=true;
	bool flag=true;
	for (int i=1;i<=n;i++)
		if (!st[i]){
			flag=false;
			break;
		}
	if (flag){
		ans=min(ans,res);
		return;
	}
	for (int i=h[u];~i;i=ne[i]){
		int v=e[i];
		if (st[v]) continue;
		res+=w[i];
		dfs(v);
		res-=w[i];
		st[v]=false;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(w,0x3f,sizeof w);
	scanf("%d%d%d",&n,&m,&k);
	int maxx=0;
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
		maxx=max(maxx,c);
	}
	for (int i=1;i<=k;i++){
		int c;
		scanf("%d",&c);
		for (int j=1;j<=n;j++) scanf("%d",&a[j]);
		if (c>=maxx) continue;
		for (int j=1;j<=n;j++)
			for (int t=j+1;t<=n;t++){
				add(j,t,a[i]+a[t]+c);
				add(j,t,a[i]+a[t]+c);
			}
	}
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
