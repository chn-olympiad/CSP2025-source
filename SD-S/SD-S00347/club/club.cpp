#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=205;
const int M=1e6+50;
int member[N][3],n;
int ans;
int lim[4],T;
int mem[N][N][N];
int maxx[M];
int dfs(int cur,int a,int b,int c){
	int sum=-1;
	if(cur==n+1) return 0;
	if(mem[cur][a][b]) return mem[cur][a][b];
	if(a<n/2)	sum=max(sum,dfs(cur+1,a+1,b,c)+member[cur][1]);
	if(b<n/2) 	sum=max(sum,dfs(cur+1,a,b+1,c)+member[cur][2]);
	if(c<n/2) 	sum=max(sum,dfs(cur+1,a,b,c+1)+member[cur][3]);
	return mem[cur][a][b]=sum;
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		memset(lim,0,sizeof lim);
		memset(mem,0,sizeof mem);
		ans=-1;
		scanf("%lld",&n);
		int A=1,B=1,C=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&member[i][j]);
				maxx[i]=max(maxx[i],member[i][j]);
			}
			if(member[i][3]!=0) A=0,B=0;
			if(member[i][2]!=0) A=0;
		}
		if(A==1){
			int sum=0;
			sort(maxx+1,maxx+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=maxx[i];
			}
			cout<<sum<<'\n';
		}
		else 
			cout<<dfs(1,0,0,0)<<'\n';
	}
	return 0;
}
