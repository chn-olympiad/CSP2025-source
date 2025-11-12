#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

void mian();

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while (t--) mian();
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

int n, arr[3][100008], cnts[3], st[48], st_t = 0, ans = 0,
rg[100008];

void df() {
	if (cnts[0] > (n >> 1) or cnts[1] > (n >> 1) or cnts[2] > (n >> 1))
		return;
	if (st_t == n) {
		int sm = 0;
		for (int i = 0; i < n; i++) {
			sm += arr[st[i]][i];
		}
		ans = max(ans, sm);
		return;
	}
	++st_t;
	st[st_t - 1] = 0;
	++cnts[0];
	df();
	--cnts[0];
	st[st_t - 1] = 1;
	++cnts[1];
	df();
	--cnts[1];
	st[st_t - 1] = 2;
	++cnts[2];
	df();
	--cnts[2];
	--st_t;
}

bool cmp(int a, int b) {
	return abs(arr[0][a] - arr[1][a]) > abs(arr[0][b] - arr[1][b]);
}

inline
void mian() {
	ans = 0;
	cnts[2] = cnts[1] = cnts[0] = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	}
	if (n <= 30) {
		df();
		cout << ans << "\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		rg[i] = i;
	}
	sort(rg, rg + n, cmp);
	for (int i = 0; i < n; i++) {
		if (
			(arr[0][rg[i]] > arr[1][rg[i]] and cnts[0] < (n >> 1))
				or cnts[1] >= (n >> 1)) {
			++cnts[0];
			ans += arr[0][rg[i]];
		} else {
			++cnts[1];
			ans += arr[1][rg[i]];
		}
	}
	
	cout << ans << "\n";
	
	return;
}

