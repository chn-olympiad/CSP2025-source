#include <bits/stdc++.h>

using namespace std;

const int N = 998244353;
int arr[5005];
long long sum;
int n;

void dfs(int mx, long sm, int val) {
	
	if (arr[val] > mx)
		mx = arr[val];
	
	sm += arr[val];
	
	if (sm > mx * 2) {
		sum++;
		
		if (sum >= N)
			sum %= N;
	}
	
	for (int i = 1; i < n - val; i++)
		dfs(mx, sm, val + i);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	for (int  i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i <= n - 3; i++)
		dfs(0, 0, i);
		
	cout << sum;
	
	return 0;
}
