#include <bits/stdc++.h>
using namespace std;
string a;
vector<int> cnt;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
		cin >> a;
	for(int i = 0; i < a.size(); i ++) {
		if (a[i] >= '0' && a[i] <= '9') {
			cnt.push_back(a[i] - '0');
		}
	}
	int s = cnt.size(), v;
	for(int i = 0; i < s; i ++){
		if (cnt[i] < cnt[i + 1]){
			v = cnt[i];
			cnt[i] = cnt[i + 1];
			cnt[i + 1] = v;
			
		}
	
	}
	for (int i = 0; i < cnt.size(); i ++) {
		cout << cnt[i];
	}
	return 0;
}
