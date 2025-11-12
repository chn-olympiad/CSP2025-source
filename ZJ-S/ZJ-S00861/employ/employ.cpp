#include <iostream>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

const int N = 5e2 + 10;
const int mod = 998244353;
int c[N];
int s[N];
int sum[N];
int n, m;

bool checkA(){
	for (int i = 1;i <= n;i ++){
		if (s[i] == 0){
			return false;
		}
	}
	return true;
}

int main(){
	fast;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		s[i] = getchar() - '0';
		sum[i] = sum[i - 1] + (s[i] == 0);
	}
	for (int i = 1;i <= n;i ++){
		cin >> c[i];
	}
	if (checkA()){
		ll ans = 1;
		for (int i = 1;i <= n;i ++){
			ans *= i;
			ans %= mod;
		}
	} else {
		cout << 114514 << endl;
	}
	return 0;
}
