#include<bits/stdc++.h>
using namespace std;
int n, m, a[105], num, k;
bool cmp(int x, int y) {
	if(x > y) return 1;
	return 0;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 0;i < n * m;i++) 
		cin >> a[i];
	num = a[0];
	sort(a, a + n * m, cmp);
	for(int i = 0;i < n * m;i++) 
		if(a[i] == num) {
			k = i + 1;
			break;
		}
	if(k / n % 2 == 0) 
		cout << ceil(k * 1.0 / n) << " " << k % n;
	else if(k % n == 0) cout << ceil(k * 1.0 / n) << " " << n;
	else cout << ceil(k * 1.0 / n) << " " << n - k % n + 1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}