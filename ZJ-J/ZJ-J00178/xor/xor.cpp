#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int a[N];
int dp[N][N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=dp[i][j-1]^a[j];
		}
	}
	int ans=0;
	int j=0;
	int x=0,y=0;
	for(int t=1;t<=n;t++){
		for(int i=1;i+j<=n;i++){
			if(i<=x && (i+j)>=y  || i>=x && i<=y || i+j>=x && i+j<=y)
				continue;
			else if(dp[i][i+j]==k){
				ans++;
				x=N;
				x=min(x,i);
				y=max(y,i+j);
			}
		}
		j++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}