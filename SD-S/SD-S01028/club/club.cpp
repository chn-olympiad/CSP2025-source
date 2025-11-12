#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N][3];
long long ans;
void dfs(int k,int c1,int c2,int c3,long long s){
	if(k>n){
		if(c1<=n/2&&c2<=n/2&&c3<=n/2&&s>ans)
			ans=s;
		return;
	}
	dfs(k+1,c1+1,c2,c3,s+a[k][0]);
	dfs(k+1,c1,c2+1,c3,s+a[k][1]);
	dfs(k+1,c1,c2,c3+1,s+a[k][2]);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	if(n<=10){
		dfs(1,0,0,0,0);
		printf("%lld",ans);
		return ;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		solve();
		if(t) printf("\n");
	}
	return 0;
}
