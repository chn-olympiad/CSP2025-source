#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,mod=998244353;
int a[maxn],n,c[maxn][maxn],ans=0;
bool teshu=true;
void dfs(int num,int x,int sum,int big){
	if(x>n){
		if(sum>big*2 && num>=3){
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(num+1,x+1,sum+a[x],max(big,a[x]));
	dfs(num,x+1,sum,big);
}
void solve(){
	dfs(0,1,0,0);
	cout << ans << endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			teshu=false;
		}
		c[i][0]=1;
	}
	if(!teshu){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			//cout << i << " " << j << " " << c[i][j] << endl;
		}
	}
	for(int i=3;i<=n;i++){
		ans+=c[n][i];
		ans%=mod;
	}
	cout << ans;
}