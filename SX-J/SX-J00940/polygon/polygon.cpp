#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int n, l[N], sm,mx;

int main{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "r", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
		sm += l[i],mx=max(mx,l[i]);
	}
	if (n <= 3){
		if(sm>mx*2) cout<<1;
	}
	return 0;
}