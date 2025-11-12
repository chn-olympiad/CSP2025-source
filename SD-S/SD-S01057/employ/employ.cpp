#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
ll n,m,c[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n!=m){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if(!c[i])	cnt++;
		}
		ll ans=1;
		for(ll i=1;i<=n-cnt;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
	} 
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			if((!c[i])||s[i]=='0')	cnt++;
		}
		if(cnt){
			cout<<0;
			return 0;
		}
		ll ans=1;
		for(ll i=1;i<=n-cnt;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
	}
	return 0;
}

