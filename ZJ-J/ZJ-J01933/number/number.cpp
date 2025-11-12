#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[30];
int k = 1;
set<int> a;
bool cmp(int a, int b){
	return a > b;
}
int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	// cout << n;
	for (int i = 0; i < n; i++){
		// cout << s[i] << ' ';
		if (s[i] >= '0' && s[i] <= '9'){
			// cout << "yes" << ' ';
			// a.push(s[i] - '0');
			cnt[s[i] - '0']++;
		}
	}
	// sort(a+1, a+1+k, cmp);
	for (int i = 9; i >= 0; i--){
		for (int j = 1; j <= cnt[i]; j++){
			cout << i;
		}
	}
	
	return 0;
}