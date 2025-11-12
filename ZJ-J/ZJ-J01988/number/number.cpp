#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 1e5 + 7, M = 1e4;
priority_queue<int> q;
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	return ;
}
void __init() {
	file();
	IOS(); 
	return ;
} 
string str;
void solve() {
	cin >> str;
	int n = str.size();
	for (int i = 0; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			q.push(str[i] - '0');
		}
	}
	while (!q.empty()) {
		int a = q.top();
		cout << a;
		q.pop();
	}
	return ;
}
int main() {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve(); 
	}
	return 0; 
}
