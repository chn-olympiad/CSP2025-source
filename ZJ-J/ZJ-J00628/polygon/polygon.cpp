#include<bits/stdc++.h>
#define ls k<<1
#define rs k<<1|1
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,a[nmax];
const int mod = 998244353;
ll ans;
ll sum[nmax];
ll dp[5001][5001];
int limit_a;
ll fast_pow(ll b){
 ll res=1;ll a=2;
 while(b){
  if(b&1)res*=a,res%=mod;
  a*=a;a%=mod;
  b/=2;
 }
 return res;
}
/*
sort(a1...n)

we find dp[i][k] :
qian i ge shu zhong
you ji zhong xuan fa de he <= k

for(i=1...n)
 ans+=fast_pow(2,i-1)-1-dp[i-1][a[i]]
 ans%=mod
*/
//11:25 da yang li guo le
int main() {
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
 ios::sync_with_stdio(0);
 cin.tie(0);cout.tie(0);
 cin>>n;
 for(int i=1;i <=n; i ++) {
  cin >>a[i];limit_a=max(limit_a,a[i]);
 }
 sort(a+1,a+1+n);
// for(int rp  =1;rp <=n;rp ++)
// {
// 	sum[i]=sum[i-1]+a[i];
// }
// for(int k=3;k<=n;k++){
//  ll all=sum[k];
//  ll cnt=(all>2*a[k]);
//  for(int i=k+1;i<=n;i++){
//  
//  }
// }

for(int i=a[1];i<=limit_a;i++)dp[1][i]=1;
 for(int i = 2;i <= n;i ++){
  dp[i][a[i]]=dp[i-1][a[i]]+1;
  dp[i][a[i]]%=mod;
  for(int m=0;m<=limit_a;m++){
  	dp[i][m]=dp[i-1][m];
 	if(a[i]>m)continue;
 	dp[i][m]=dp[i][m]+dp[i-1][m-a[i]]+1;
 	dp[i][m]%=mod;
  }
}
 for(int i = 2;i <=n;i ++){
  ll v=dp[i-1][a[i]];
  ll v2=fast_pow(i-1)-1;
  ans+=((v2-v)%mod+mod)%mod;
  ans%=mod;
 }
 cout<<ans;
 return 0;
}