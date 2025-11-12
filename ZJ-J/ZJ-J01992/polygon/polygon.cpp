#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=5e3+50;
const int inf=1e17;
const int mod=998244353;
int n;
int a[N];
int dp[2][M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		if(i>2){
			int sum=0;
			for(int j=5005;j>=a[i];j--){
				sum+=dp[(i-1)%2][j];
				sum%=mod;
			}
			ans+=sum;
			ans%=mod;
		}
		//no choose a_i
		for(int j=0;j<=5001;j++){
			dp[i%2][j]=dp[(i-1)%2][j];
			dp[i%2][j]%=mod;
		}
		//choose a_i and total=2
		for(int j=1;j<i;j++){
			dp[i%2][min(a[j]+a[i]-1,5001ll)]++;
			dp[i%2][min(a[j]+a[i]-1,5001ll)]%=mod;
		}
		//choose a_i ans total>2
		for(int j=0;j<=5001;j++){
			if(!dp[(i-1)%2][j]){
				continue;
			}
			dp[i%2][min(j+a[i],5001ll)]+=dp[(i-1)%2][j];
			dp[i%2][min(j+a[i],5001ll)]%=mod;
		}
	}
	ans%=mod;
	cout<<ans<<endl;
	return 0;
}
//pts 100
//Shui
