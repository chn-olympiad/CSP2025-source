#include <iostream>
#include <set>
#define ll long long

using namespace std;

int n, k, arr[500008], arr_sm[500008], ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr_sm[i + 1] = arr_sm[i] ^ arr[i];
	}
	set<int> vis;
	for (int i = 0; i <= n; i++) {
		if (vis.count(arr_sm[i])) {
			vis.clear();
			ans++;
//			continue;
		}
		vis.insert(arr_sm[i] ^ k);
	}
	
	cout << ans << "\n";
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

