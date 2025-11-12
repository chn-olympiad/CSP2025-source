#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
bool ifp(vector<int> a){
	int sum = 0;
	for(int i = 0;i < a.size() - 1;i++)
		sum += a[i];
	if(sum > a[a.size() - 1])
		return true;
	else
		return false;
}
void dfs(int x, int a[], vector<int> num){
	if(x > n)
		return;
	if(num.size() > 2 && ifp(num)){
		ans++;
	}
	for(int k = x + 1;k < n;k++){
		num.push_back(a[k]);
		dfs(k, a, num);
		num.pop_back();
	}
}
int main(){
	cin.tie();cout.tie();
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++)
		cin >> a[i];
	if(n < 3){
		cout << 0;
		return 0;
	}
	sort(a , a + n);
	dfs(-1, a, {});
	cout << ans % 998244353;
	return 0;
}
