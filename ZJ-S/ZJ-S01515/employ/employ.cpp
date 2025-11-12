#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,cnt,num;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>num;
	string s; cin>>s;
	for(int i=1;i<=n;i++){
		ll x;cin>>x;
		if(x) cnt++;
	}
	cout<<cnt%mod*(cnt-1)%mod/2;
	return 0;
}
