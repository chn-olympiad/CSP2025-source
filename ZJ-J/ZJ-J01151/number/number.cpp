#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, a[N];
string s;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i ++){
		if (s[i] <= '9' && s[i] >= '0'){
			a[s[i] - '0'] += 1;
		}
	}
	for (int i = 9; i >= 0; i --){
		for (int j = 1; j <= a[i]; j ++){
			cout << i;
		}
	}
	return 0;
}
