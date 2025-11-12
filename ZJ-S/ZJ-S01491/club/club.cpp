#include<bits/stdc++.h>
using namespace std;
int t,n,A[100005][3],dp[10005][3],k[5],b[100005];
long long ans=0;
void dfs(long long sum,int i,int a,int b,int c){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	if(a+1<=n/2) dfs(sum+A[i][1],i+1,a+1,b,c);
	if(b+1<=n/2) dfs(sum+A[i][2],i+1,a,b+1,c);
	if(c+1<=n/2) dfs(sum+A[i][3],i+1,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	int ok=0;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>A[i][j];
				if(j!=1){
					if(A[i][j]!=0) ok=1;
				}
			}
		}
		if(n<30){
			dfs(A[1][1],2,1,0,0);
			dfs(A[1][2],2,0,1,0);
			dfs(A[1][3],2,0,0,1);
			cout<<ans<<"\n";
			ans=0;
		} 
		else if(ok==0){
			for(int i=1;i<=n;i++){
				b[i]=A[i][1];
			}
			sort(1+b,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}