#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod= 998244353;
int n,mx;
long long cnt;
int a[N];
int dp[N][N];
bool vis[N];
int sum=0;
void dfs(int mx,int x,int last){
	if(x>mx){
		if(sum>2*a[last]){
			cnt=(cnt+1)%mod;
		}
		return;
	}
	for(int i=last+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			sum+=a[i];
			dfs(mx,x+1,i);
			vis[i]=0;
			sum-=a[i];
		}	
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(mx==1){
		dp[1][1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(j==1){
					dp[i][j]=i;
				}else{
					dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;	
				}		
			}
		}
		for(int i=3;i<=n;i++){
			cnt=(cnt+dp[n][i])%mod;
		}
		cout<<cnt;
		return 0;
	}
	
	for(int i=3;i<=n;i++){
		dfs(i,1,0);	
	}
	cout<<cnt;
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
