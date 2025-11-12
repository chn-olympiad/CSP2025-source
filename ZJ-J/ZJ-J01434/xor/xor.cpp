#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,k,t=1,ans;
ll dp[514514];
bool f[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		f[0]=1;
		cin>>x;
		dp[i]=dp[i-1]^x;
		if(f[k^dp[i]]){
			ans++;dp[i]=0;
			for(int j=t;j<i;j++) f[dp[j]]=0;
			t=i+1;
			continue;
		}
		f[dp[i]]=1;
	}
	cout<<ans;
	return 0;
}