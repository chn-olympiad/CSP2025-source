#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=505;
ll mod=998244353;
ll n,m,ans;
ll pa[N];
ll ch[N];
ll vis[N],res[N];
string s;
void dfs(int k){
	if(k==n+1){
		int wr=0,tick=0;
		for(int i=1;i<=n;i++){
		//	cout<<ch[i]<<' ';
			if(s[i]=='0' || wr>=pa[ch[i]]){
				wr++;
			}
			else if(s[i]=='1'){
				tick++;
			}
		}
		if(tick>=m) ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			ch[k]=i;
			vis[i]=1;
			dfs(k+1);
			ch[k]=0;
			vis[i]=0;
		}
	}
}
ll quick_power(ll x,ll po){
	ll res=x;ll ans=1;
	while(po){
		if(po&1){
			ans=ans*res%mod;
		}
		res=res*res;
		po>>=1;
	}
	return ans;
}
ll C(ll a,ll b){
	ll f=res[b]*res[a-b]%mod;
	ll xx=res[a]*(quick_power(f,mod-2))%mod;
	return xx;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//cout<<quick_power(2,5);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	res[0]=1; 
	for(int i=1;i<=n;i++){
		res[i]=res[i-1]*i%mod;
	}
	int ts=0;
	for(int i=1;i<=n;i++){
		cin>>pa[i];
		if(pa[i]==0){
			ts++;
		}
	}
	//cout<<ts<<' '<<m;
	if(n<=10){
		dfs(1);
		cout<<ans%mod<<endl;
	}
	else if(n-ts<m) {
		cout<<0<<endl;
		return 0;
	}
	else if(m==n){
		int cnt=0;
		for(int i=1;i<=s.size()-1;i++){
			if(s[i]=='1') cnt++;
		}
		if(cnt==m){
			cout<<res[n]<<endl;
		}
		else cout<<0<<endl;
	}
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
