#include <bits/stdc++.h>

using namespace std;

int n, m;

struct e {
	int f, num;
} a[105];

bool cmp(e a, e b) {
	return a.f > b.f;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++) {
		cin >> a[i].f;
		a[i].num = i;
	}
	sort(a+1, a+n*m+1, cmp); 
	int i = 1, j = 1, l = 1;
	bool p = 0;
	while(1) {
		if(a[l].num == 1) {
			cout << j << ' ' << i;
			return 0;
		}
		l++;
		if(!p) {
			i++;
			if(i > n) {
				j++;
				i--;
				p = 1;
			}
		} else {
			i--;
			if(i < 1) {
				j++;
				i++;
				p = 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
