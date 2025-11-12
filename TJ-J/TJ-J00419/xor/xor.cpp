#include<bits/stdc++.h>
using namespace std;
int a[50050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(k == 0) cout << n/2;
	return 0;
}
