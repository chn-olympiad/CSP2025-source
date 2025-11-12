#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
string s1[200005],s2[200005],t1,t2;
//map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
		//mp[s1[i]] = s2[i];
	}
	for (int i = 1;i <= q;i++){
		cin >> t1 >> t2;
		ll ans = 0,start,endd;
		ll n1 = t1.length();
		if (n1 != t2.length()){
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0;i < n1;i++){
			if (t1[i] != t2[i]){
				start = i;
				break;
			}
		}
		for (int i = n1;i >= 0;i--){
			if (t1[i] != t2[i]){
				endd = i;
				break;
			}
		}
		for (int i = 1;i <= n;i++){
			if (s1[i] != t1)continue;
			string x = t1.substr(0,(start - 1));
			string z = t1.substr(min(n1,(ll)endd + 1),n1 - (ll)endd);
			string now = x + s2[i] + z;
			if (now == t2) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}

