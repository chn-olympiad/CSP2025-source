#include<bits/stdc++.h>
using namespace std;

const int NM = 5e2,mod = 998244353;
int A[NM+4],T[NM+4];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	bool f = 1;
	for(int i = 1;i <= n;i++) cin>>A[i];
	for(int i = 1;i <= n;i++) T[i] = i;
	int len = s.length();
	for(int i = 0;i < len;i++) if(s[i] == '0' or A[i+1] == 0) f = 0;
	if(f){
		int dp[n+4] = {};
		dp[0] = 1;
		for(int i = 1;i <= n;i++) dp[i] = dp[i-1]*i%mod;
		cout<<dp[n]<<'\n';
		return 0;
	}
	do{
		int cnt = 0,last = 0;
		for(int i = 1;i <= n;i++){
			if(last >= A[T[i]]) {last++;continue;}
			if(s[i-1] == '1') cnt++;
			else last++;
			if(cnt >= m) {ans = (ans+1)%mod;break;}
		}
	}while(next_permutation(T+1,T+1+n));
	cout<<ans;
	return 0;
}
