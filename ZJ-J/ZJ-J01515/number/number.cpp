#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000002], k;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		int t = s[i] - '0';
		if (t >= 0 && t <= 9){
			a[k] = t;
			k++;
		}
	}
	sort(a, a + k);
	for (int i = k - 1; i >= 0; i--){
		cout << a[i];
	}
	return 0;
}
