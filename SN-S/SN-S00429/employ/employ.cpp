#include <bits/stdc++.h>
using namespace std;

int a, b;
int ans = 1;
int main() {
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	cin >> a;
	for(int i=1;i<=a;i++) {
		ans *= i;
	}
	cout <<ans;
	
	return 0;
}

