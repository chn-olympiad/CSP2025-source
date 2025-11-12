#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define inf INT_MAX
#define fi first
#define se second
const int maxn=1e4+20,mod=998244353;

int n,m,x,k,ans;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	if(m==n){
		cout<<m*(m-1)%mod;
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	ans=m+1;
	for(int i=m+2;i<=n;i++){
		ans=ans*i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}