#include <iostream>
#include <vector>
using namespace std;
long long arr[5050], n, rst =0;
void dfs(vector<int> v) {
	int sum = 0, ma = 0;
	for(int i = 0; i < v.size(); i++) {
		sum += arr[v[i]];
		if(ma < arr[v[i]]) {
			ma = arr[v[i]];
		}
//		cout << v[i] + 1 << ' ';
	}
	//cout << endl;
	if(sum > ma * 2) {
		rst++;
//		for(int i = 0; i < v.size(); i++) {
//			cout << v[i] + 1 << ' ';
//		}
//		cout << endl;
//		cout << sum << ' ' << ma << endl;
		rst %= 998244353;
	}
	for(int i = v[v.size() - 1] + 1; i < n; i++) {
		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
}
int main() {
	freopen("polygon.out", "w", stdout);
	freopen("polygon.in", "r", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> v;
	v.push_back(0);
	for(int i = 0; i < n; i++) {
		v[0] = i;
		dfs(v);
	}


	cout << rst % 998244353;
}