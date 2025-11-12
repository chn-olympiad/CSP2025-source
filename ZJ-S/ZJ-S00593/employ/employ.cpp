#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[510];
string s;
ll n,m;
bool check(){
	for(int i=0;i<n;i++) if(s[i]=='0') return 0;
	return 1;
}
const int MOD=998244353;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		if(!check()){
			cout<<0;
			return 0;
		}
		sort(c+1,c+1+n);
		ll cnt=c[1];
		ll tmp=1;
		for(int i=2;i<=n;i++){
			cnt=cnt*((c[i]-tmp)%MOD)%MOD;
			tmp++;
		}
		if(cnt<=0) cout<<0;
		else cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
}
