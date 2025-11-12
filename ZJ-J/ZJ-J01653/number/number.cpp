#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int a[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
	int idx = 0;
	for(int i = 0;i < s.size();i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[++idx] = s[i] - '0';
		}
	}
	sort(a + 1,a + 1 + idx);
	for(int i = idx;i >= 1;i --) cout << a[i];
	return 0;
}
