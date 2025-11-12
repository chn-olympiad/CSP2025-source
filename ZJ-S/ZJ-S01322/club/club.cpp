#include<bits/stdc++.h>
using namespace std;
struct person{
	int first, second, third;
}a[514514];
int n, mx = -1e9, a1, a2, a3, MAX = 0;
void dfs(int g, int r, int sum) {
//	cout << g << " " << r <<" " << sum <<'\n';
//	cout <<a1<<" "<<a2<<" "<<a3<<'\n';
	if (r == 1) a1++;
	else if (r == 2) a2++;
	else a3++;
	if (a1 > MAX || a2 > MAX || a3 > MAX) {
		if (r == 1) a1--;
		else if (r == 2) a2--;
		else a3--;
//		cout<<"---WRONG---"<<'\n';
		return;
	}
	if (g == n + 1) {
		mx = max(mx , sum);
		if (r == 1) a1--;
		else if (r == 2) a2--;
		else a3--;
//		cout << "---END---"<<'\n';
		return ;
	}
	if (r == 1) {
		dfs(g + 1, 1, sum + a[g].first);
		dfs(g + 1, 2, sum + a[g].first);
		dfs(g + 1, 3, sum + a[g].first);
	}
	else if (r == 2) {
		dfs(g + 1, 1, sum + a[g].second);
		dfs(g + 1, 2, sum + a[g].second);
		dfs(g + 1, 3, sum + a[g].second);
	}
	else {
		dfs(g + 1, 1, sum + a[g].third);
		dfs(g + 1, 2, sum + a[g].third);
		dfs(g + 1, 3, sum + a[g].third);
	}
	
	if (r == 1) a1--;
	else if (r == 2) a2--;
	else a3--;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		mx = -1e9;
		cin >> n;
		MAX = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i]. first >> a[i].second >> a[i].third;
		}
		a1 = 0, a2 = 0, a3 = 0;
		dfs(1, 1, 0);
		a1 = 0, a2 = 0, a3 = 0;
		dfs(1, 2, 0);
		a1 = 0, a2 = 0, a3 = 0;
		dfs(1, 3, 0);
//		cout <<"------ANS------\n";
		cout << mx << '\n';
//		cout <<"---------------\n";
	}
	
	
	
	
	return 0;
}
