#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, R, c, r, idx;
int a[N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i];
	}R = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1;i <= n * m;i++){
		if (a[i] == R){
			idx = i;
			break;
		}
	}
	if (idx % n == 0){
		c = idx / n;
		if (c % 2)r = n;
		else r = 1;
	}else{
		int p = idx / n;
		c = p + 1;
		if (c % 2)r = idx % n;
		else r = n - idx % n + 1;
	}cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
