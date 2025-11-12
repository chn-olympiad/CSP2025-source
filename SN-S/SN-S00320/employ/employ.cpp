#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[11], c[11], cnt;
char s[11];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++){
		a[i] = i;
		cin >> c[i];
	}
	do{
		int sum = 0;
		for (int i = 1; i <= n; i++){
			if (sum >= c[a[i]] || s[i] != '1') sum++;
		}
		if (n - sum >= m) cnt++;
	}while(next_permutation(a + 1, a + 1 + n));
	cout << cnt;
	return 0;
}
