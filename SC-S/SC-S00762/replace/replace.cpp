#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;
string s[N],ss[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)cin >> s[i] >> ss[i];
	while(q--){
		int ans = 0;
		string t,tt;
		cin >> t >> tt;
		if(t.size() != tt.size()){
			cout << "0\n";
			continue;
		}
		for(int i = 1; i <= n; ++i){
			string jl = t;
			if(t.find(s[i]) != -1){
				int wz = t.find(s[i]),cd = s[i].size();
				for(int j = wz,k = 0; k < cd; ++k,++j)
					jl[j] = ss[i][k];
				if(jl == tt)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}