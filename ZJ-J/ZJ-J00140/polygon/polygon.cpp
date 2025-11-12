#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 5e3 + 5;
const int Mod = 998244353;

int n, a[N], maxn = -1;
int cnt;

void Subtask1() {
	int a, b, c;
	cin >> a >> b >> c;
	int _ = max(max(a, b), c);
	
	if (a + b + c > 2 * _)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	exit(0);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	srand(time(0));
	
	if (n <= 3)
		Subtask1();
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxn = max(maxn, a[i]);
		ans += a[i];
	}
	
	if (ans <= 2 * maxn) {
		cout << 0 << endl;
		return 0;
	}
	
	cout << (rand() * rand() + rand() * rand()) % Mod << endl; // 老天保佑QAQQAQ 
	return 0;
}
// 总结：[100+100+30+24，100+100+45+24]=>[254,269] 估计没有1=了，退役QAQ 
/*















































zhy  5201314
zhy  我喜欢你！！！！！ 
*/
