#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1100000000000000;
int g[10100][10100];
int n,m;
long long dist[10001];
int k,s[11];
bool st[100001];
long long prim(){
	long long sum=0;
	for(int i=1;i<=n;i++) dist[i]=MAXN;
	dist[1]=0;
	for(int i=1;i<=n;i++){
		int t=-1;
		for(int j=1;j<=n;j++){
			if(!st[j]&&(t==-1||dist[t]>dist[j])){
				t=j;
			}
		}
		if(i>1) sum+=dist[t];
		st[t]=true;
		for(int j=1;j<=n;j++)
		{
			long long k=(long long)g[t][j];
			dist[j]=min(dist[j],k);
		}
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		g[a][b]=c;
		g[b][a]=c;
	}
	cout<<prim();
	return 0;
}

