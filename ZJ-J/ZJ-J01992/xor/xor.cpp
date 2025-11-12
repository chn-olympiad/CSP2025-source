#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=1e9+7;
int n,k;
int a[N];
int sum[N];
int las[N];
int f[N];
int dp[N][2];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		f[i]=las[sum[i]^k];
		las[sum[i]]=i;
//		cout<<sum[i-1]<<" xor "<<a[i]<<" = "<<sum[i]<<"      "<<(sum[i]^k)<<' '<<f[i]<<' '<<las[sum[i]^k]<<endl;
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);	//no choose a_i
		//choose a_i
//		cout<<i<<' ';
		if(f[i]){
//			cout<<" f "<<f[i]<<' ';
			dp[i][1]=max(dp[f[i]][0],dp[f[i]][1])+1;
		}else{
			if((sum[i]^k)==0){
//			cout<<" sum "<<sum[i]<<' '<<(sum[i]^k)<<' ';
				dp[i][1]=1;
			}
		}
//		cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
	return 0;
}
//pts 100
//Ruo
