#include<bits/stdc++.h>
using namespace std;
long long n, m, c[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	int cnt = 1;
	for (int i = 0; i < s.length(); i++) if (s[i] == '0') cnt--;
	cout << cnt << "\n";
	return 0;
}

