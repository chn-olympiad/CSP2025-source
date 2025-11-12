#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+5;
string s1[N], s2[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> q >> n;

	for(int i=1; i<=n; ++i)cin >> s1[i] >> s2[i];
	vector<int>a(n+1);
	while(q--){
		string t1, t2;
		cin >> t1 >> t2;
		int cnt=0;
		for(int i=1; i<=n; ++i){
			for(int j=0; j < s1[i].size(); ++j){
				if(s1[i][j] != t1[cnt]||s2[i][j]!=t2[cnt])cnt=0;
				else{
					cnt++;
					if(cnt==t1.size())a[i]++;
				}
			}
		}
	}
	for(int i=1; i<=n; ++i)cout << a[i] << '\n';
	return 0;
}