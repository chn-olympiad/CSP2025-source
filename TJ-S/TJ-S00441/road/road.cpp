#include<bits/stdc++.h>
using namespace std;
const int N=1e4+30,M=1e5+1;
int n,m,k;
long long a[N][N];
long long c[N];
bool d[N];
bool vis[N][N];
long long pre[N];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int st=n;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u][v]=a[v][u]=w;
		vis[u][v]=vis[v][u]=1;
	}
	for(int i=1;i<=k;i++){
		n++;
		long long bld;
		cin>>bld;
		for(int j=1;j<=st;j++){
			scanf("%lld",&a[n][j]);
			a[j][n]=a[n][j]+bld;
			vis[j][n]=vis[n][j]=1;
		}
	}
	for(int i=1;i<=n;i++) c[i]=0x7fffffff;
	int f=1;
	d[1]=1;
	for(int ii=1;ii<=n-1;ii++){
		long long mn=0x7fffffff;
		int flag=f;
		for(int i=1;i<=n;i++){
			if(vis[f][i]==1&&d[i]==0){
				int befc=c[i];
				c[i]=min(c[i],a[f][i]);
				if(befc!=c[i]) pre[i]=f;
			}
			if(mn>c[i]&&d[i]==0){
				flag=i;
				mn=c[i];
			}
		}
		if(flag>=st+1){
			for(int i=1;i<=st;i++){
				if(i!=flag) a[flag][i]+=a[pre[flag]][flag];
			}
		}else sum+=mn;
		d[flag]=1;
		f=flag;
	}
	cout<<sum;
	return 0;
}
