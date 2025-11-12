#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll modr = 998244353;
ll dp[25000010];
ll nbr[5050];
ll qzh[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,sum=0; cin >> n;
	for(int i=1;i<=n;i++) scanf("%lli",&nbr[i]);
	sort(nbr+1,nbr+n+1);
	for(int i=1;i<=n;i++){
		sum+=nbr[i];
		qzh[i] = qzh[i-1] + nbr[i];
	}ll cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=1;j--){
			if(j>nbr[i]) dp[j] += dp[j-nbr[i]]+(j>=nbr[i]);
			else dp[j] += (j>=nbr[i]);
			dp[j] %= modr;
		}
		if(qzh[i+1]<=nbr[i+1]) continue;
		cnt += dp[qzh[i+1]]-dp[nbr[i+1]];
		cnt %= modr;
	}
	cout << cnt;
	return 0;
} 
