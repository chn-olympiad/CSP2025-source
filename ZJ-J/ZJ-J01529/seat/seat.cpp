#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, t, k, t1, a[N];
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	k = 1;
	while(a[k] != t) k++;
	int t1 = (k - 1) % n;
	//cout << k << " ";
	cout << ceil(k * 1.0 / n) << " ";
	if(int(ceil(k *1.0 / n)) % 2) cout << t1 + 1;
	else cout << n - t1;
	return 0;
}
