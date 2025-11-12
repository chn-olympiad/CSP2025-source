//何侣佟-SN-J00036-西安滨河学校
#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	if(a[0]+a[1]>a[2]) {
		cout << 1;
		return 0;
	}
	cout << 0;
	return 0;
}

