#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int nmax = 1159764;

int n,m;
string s;
int c[nmax],player[nmax];
const int mod = 998244353;
void solve() {
  cin >>n>>m>>s;ll cnt0=0;
  for(int i=1; i<=n; i++)
    player[i]=i,cin >>c[i],cnt0+=(c[i]==0);
  
  ll cnt1=0;
  for(int i=0;i < n;i ++)
  cnt1+=s[i]-48;
  
  if(cnt1==n){
  	if(n-cnt0<m){
  		cout<<0;return;
	  }
	  
	  ll fac=1;
  	for(ll i=2;i<=n;i++){
  		fac*=i;
  		fac%=mod;
	  }
	  cout<<fac;
  	return ;
  }
  ll ans=0;
  do{
  	
  	ll now_killed=0;
  	for(int i = 0;i <n;i++){
  		if(now_killed>=c[player[i+1]]){
		  now_killed++;continue;}
		  
		  if(s[i]=='0'){
  			now_killed++;
		  }
		
	  }
	ll wehave=n-now_killed;
	ans+=(wehave>=m);
  }while(next_permutation(player+1,player+1+n));
  cout<<ans;
  return;
  cout<<"CSP-S 2025 rp++!";
}
int main() {
  freopen("employ.in","r",stdin);
  freopen("employ.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll T=1;
  while(T--)solve();
  return 0;
}