#include <bits/stdc++.h>
using namespace std;

long long n, k;
int a[500010], d[500010], q[500010], l[500010], r[500010], last[500010]; 
int main(){
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		d[i] = d[i-1] ^ a[i];
	}
	q[0] = 1;
	last[0] = 0;
	int ans = 0;
	int j = 1;
	for (int i = 1; i <= n; i++){
		if (q[d[i] ^ k] >= 1){
			ans++;
			q[d[i]]++;
			l[j] = last[d[i] ^ k] + 1;
			r[j] = i;
			j++; 
			last[d[i]] = i;
		}
	}
	for (int i = 2; i <= j-1; i++){
		if (l[i] <= r[i-1]){
			l[i] = 0;
			r[i] = 0;
			ans--;
		}
	}
	cout << ans;
	
	return 0;
}