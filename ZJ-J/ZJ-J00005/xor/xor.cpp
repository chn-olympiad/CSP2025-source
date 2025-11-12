#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
long long n,k,a[N],b[1005][1005],dp[N],m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],b[i][i]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i][j]=b[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(b[1][i]==k) m=1;
		else m=0;
		for(int j=2;j<=i;j++){
			int t;
			if(b[j][i]==k) t=1;
			else t=0;
			m=1ll*max(m,dp[j-1]+t);
		}
		dp[i]=m;
	}
	cout<<dp[n];
	return 0;
}
