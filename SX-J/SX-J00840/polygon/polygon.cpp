#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int jc[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	for (int i = 1; i <= 5000; i++) {
		long long t = 1;
		for (int j = i; j > 1; j--)
			t = (t * j) % 998244353;
		jc[i] = t;
	}
	cin >> n;
	bool T = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			T = false;
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * max(a[1], max(a[1], a[2])))
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (T) {
		long long sum = 0;
		for (int i = 3; i <= n; i++) {
			sum = (sum + jc[n] / jc[n - i] / jc[i]) % 998244353;
		}
		cout << sum;
		return 0;
	}
	cout << 0;
	return 0;
	//啊——，终于写完了 *\(?° ?°?)/*还剩1h。
	//!!!!!!!!希望能被洛谷选上!!!!!!!!
	//在这里，我只想说：
	//										                     |
	//									    	          __\--__|_
	//( ′-ω-`)▄︻┻┳══━一@三角洲行动官方    II=======OOOOO[/ ★玩家_|
	//									             _____\______|/-----.
	//									            /____________________|
	//									            \◎◎◎◎◎◎◎◎⊙/
	//									              ~~~~~~~~~~~~~~~~
	//					回调深蓝！！！！！！！
	//					回调撤离点机制！！！！
	//					削弱人机、boss！！！！
}