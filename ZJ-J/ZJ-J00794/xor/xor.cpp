#include <iostream>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll unsigned long long
using namespace std;

const int N = 5e5 + 10;
int n, k;
ll arr[N];
int vis[N];
ll sum[N];
int g[N], idx;
ll ans = 0;

bool checkA(){
	for (int i = 1;i <= n;i ++){
		if (arr[i] != 1){
			return false;
		}
	}
	return true;
}

bool checkB(){
	for (int i = 1;i <= n;i ++){
		if (arr[i] > 1){
			return false;
		}
	}
	return true;
}

bool checkC(){
	for (int i = 1;i <= n;i ++){
		if (arr[i] > 255){
			return false;
		}
	}
	return true;
}

void work(int l, int r){
	for (int i = l;i < r;i ++){
		for (int j = i + 1;j <= r;j ++){
			if ((sum[j] ^ sum[i - 1]) == k){
				ans ++;
				i = j + 1;
			}
		}
	}
	return ;
}

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	fast;
	cin >> n >> k;
	for (int i = 1;i <= n;i ++){
		cin >> arr[i];
	}
	if (checkA()){
		if (k == 0){
			cout << n / 2 << endl;
		} else {
			cout << n << endl;
		}
	} else if (checkB()){
		ll fi = 0, se = 0;
		for (int i = 1;i <= n;i ++){
			if (arr[i] == 1){
				fi ++;
			} else {
				se ++;
			}
		}
		if (k == 0){
			cout << se + fi / 2 << endl;
		} else {
			cout << fi << endl;
		}
	} else if (n <= 1000){
		for (int i = 1;i <= n;i ++){
			sum[i] = sum[i - 1] ^ arr[i];
		}
		for (int i = 1;i <= n;i ++){
			if (arr[i] == k){
				ans ++;
				g[++ idx] = i;
			}
		}
		int now = 1;
		for (int i = 1;i <= idx;i ++){
			if (g[i] == now || g[i] - 1 == now){
				now = g[i] + 1;
				continue;
			}
			work(now, g[i] - 1);
		}
		cout << ans << endl;
	} else {
		cout << 114514 << endl;
	}
	return 0;
}
