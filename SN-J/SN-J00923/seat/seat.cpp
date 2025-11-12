#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,g;
bool f = 1;
int a[1005];
bool cmp(int x,int y) { return x > y; }
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n * m;i++) {
		cin >> a[i];
	}
	g = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int x = 0,y = 0;
	for(int i = 1;i<=n * m;i++) {
		int y = (i + n - 1) / n;
		if(g == a[i]) {
			cout << y << " ";
			if(y % 2 == 1) {
				if(i % n == 0) cout << n;
				else cout << i % n;
			} else {
				if(i % n == 0) cout << 1;
				else cout << n - i % n + 1;	
			}
			break;
		}
	}
	return 0;
}
