#include<bits/stdc++.h>
using namespace std;
int t;
const int N=1e5+5;
long long a[N][5];
int f[N];
int n;
long long ans;
void dfs(int u,int A,int B,int C){
	if(A*2>n||B*2>n||C*2>n) return ;//¼ôÖ¦
	if(u>n){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][f[i]];
		}
		ans=max(ans,sum);
		return ;
	}
	
	f[u]=1;
	dfs(u+1,A+1,B,C);
	f[u]=2;
	dfs(u+1,A,B+1,C);
	f[u]=3;
	dfs(u+1,A,B,C+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
		}
		dfs(1,0,0,0);
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
*/
