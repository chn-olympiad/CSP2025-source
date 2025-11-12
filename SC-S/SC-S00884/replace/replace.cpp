#include<bits/stdc++.h>
using namespace std;
#define end '\n'
#define ll long long 
#define int long long 
const int N = 200005;

string s[N][3];
void solve () {
	int n, q;	
	cin >> n >>q;
	unordered_map<string, string>mp1;
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
		mp1[s[i][1]] = s[i][2];
		
	}
	while(q -- ) {
		int ans = 0;
		string a, b;
		cin >> a >> b;
		if(mp1[a] == b) ans ++;
		int i;
		for(i=0;i<min(a.size(),b.size());i++)
			if(a[i]==b[i]) continue;
			else break;
		string sa = a.substr(i);
		string sb = b.substr(i);
		while(sa.size() && sb.size() && sa.back() ==sb.back()){
			sa.pop_back();
			sb.pop_back();
		}
		if(mp1[sa]==sb) ans ++ ;
		cout << ans << endl;
		
		
	}
	
	
	
}

signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t = 1;
	while(t --) solve();
	
	
	return 0;
}
