#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q,x,y,a[1000];
string s;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		if(a[i]==0){
			x++;
		}
	}
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0'){
			y++;
		}
	}
	if(n-x<m||n-y<m){
		cout<<0<<'\n';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(a[i]) q++;
	} 
	for(ll i=q;i>=2;i--){
		ans*=i;
	}
	ans%=998244353;
	cout<<ans<<'\n';
	return 0;
}

