#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=11;
ll cnt[N];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9') cnt[s[i]-'0']++;
	}
	for(ll i=9;i>=0;i--){
		for(ll j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	cout<<'\n';
	return 0;
}
