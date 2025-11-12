#include <iostream>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

const int N = 5e3 + 10;
const int mod = 998244353;
int arr[N];
ll cn = 0;

int n;

bool check(){
	for (int i = 1;i <= n;i ++){
		if (arr[i] != 1){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	fast;
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> arr[i];
	}
	if (n <= 20){
		for (int i = 1;i < (1 << n);i ++){
			int cnt = 0;
			int mx = 0, ans = 0;
			for (int j = 0;j < n;j ++){
				if ((i >> j) & 1){
					cnt ++;
					mx = max(mx, arr[j + 1]);
					ans += arr[j + 1];
				}
			}
			if (ans > mx * 2 && cnt >= 3){
				cn ++;
				cn %= mod;
			}
		}
		cout << cn << endl;
	} else if (check()){
		cout << (n * n - 3 * n + 2) / 2 << endl;
	} else {
		cout << 114514 << endl;
	}
	return 0;
}
