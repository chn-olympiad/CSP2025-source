#include<bits/stdc++.h>
using namespace std;

int n, m, a[1000010];
string s;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = s.size();
	s = " " + s;
	for(int i = 1; i <= n; i++){
		if('0' <= s[i] && s[i] <= '9'){
			a[++m] = s[i] - '0';
		}
	}
	sort(a + 1, a + m + 1);
	for(int i = m; i >= 1; i--){
		cout << a[i];
	}
	cout << "\n";
	return 0;
}
