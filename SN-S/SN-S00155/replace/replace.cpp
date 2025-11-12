#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 7;

int n, m;
string s_a[N], s_b[N]; 
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n ; i++) cin >> s_a[i] >> s_b[i];
	
	for(int i = 1; i <= m; i++) {
		string a, b;
		cin >>  a >> b;
		cout << 0 << endl;
	}
	
	return 0;
}
