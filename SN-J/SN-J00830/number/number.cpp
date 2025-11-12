#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10;
char u[maxn];
int sum = 0;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i = 0; i < a.size(); i ++) {
		if('0' <= a[i] && a[i] <= '9') {
			sum ++;
			u[sum] = a[i];
		}
	}
	sort(u + 1,u + sum + 1);
	for(int i = sum; i >= 1; i --) {
		cout << u[i];
	}
	return 0;
}

