#include <bits/stdc++.h>
using namespace std;
int n, m, tot;
int a[105];
int score;//表示小R的成绩
int x=1, y=1;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			cin >> a[++tot];
		}
	}  score=a[1];
	sort(a+1, a+1+tot, greater<int>());
	//找到小R在哪里
	for(int i=1; i<=tot; ++i) {
		if(a[i]==score) {
			//此时的i为小R考试的排名
			int k=ceil(1.0*i/n); int r=(i%n==0)?n:i%n;
			if(k%2==1) {
				cout << k << ' ' << r;
			}
			else {
				cout << k << ' ' << n+1-r;
			}
			return 0;
		}
	}
	return 0;
}
