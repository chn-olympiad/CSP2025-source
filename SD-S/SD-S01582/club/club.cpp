#include<bits/stdc++.h>
using namespace std;
long long n,a[100005][4],t,dp[100005],s[4],mx,b[100005];
long long dfs(long long deep,long long ans,long long c1,long long c2,long long c3){
	if(deep>n+1) return ans;
	if(c1>n/2||c2>n/2||c3>n/2) return 0;
	return max(dfs(deep+1,a[deep+1][1],c1+1,c2,c3),max(dfs(deep+1,a[deep+1][2],c1,c2+1,c3),dfs(deep+1,a[deep+1][3],c1,c2,c3+1)));
}
int main(){ 
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		int k=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				b[i]=a[i][1];
				if(a[i][2]!=0){
					k=0;
				}
			}
		}
		if(k==1){
			sort(b+1,b+1+n);
			long long sd=0;
			for(int i=n;i>n-n/2;i--){
				sd+=b[i];
			}
			cout<<sd;
			
		}
		
		else if(n==2){
			cout<<max(max(max(a[1][1]+a[2][2],a[1][1]+a[2][3]),max(a[1][2]+a[2][1],a[1][2]+a[2][3])),max(a[1][3]+a[2][2],a[1][3]+a[2][1]));
			
		}
		else cout<<dfs(0,0,0,0,0);
		
	}
	return 0;
}


