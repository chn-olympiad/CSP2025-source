#include<bits/stdc++.h>
using namespace std;
struct note {
	int num;
	bool tf;
};
note a[105];
bool cmp (note a , note b) {
	return a.num > b.num;
}
int main () {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].num;
		a[i].tf = false;
	}
	a[1].tf = true;
	sort(a + 1 , a + n * m + 1 , cmp);
	int c = 1 , r = 0 , p = 0;
	bool tf = true;
	for (int i = 1; i <= n * m; i++) {
		if (r == m && tf == true) {
			c++;
			r = m;
			tf = false;	
		}
		else if (r == 1 && tf == false) {
			c++;
			r = 1;
			tf = true;
		}
		else {
			if (tf) r++;
			else r--;
		}
		p++;
		if (a[p].tf == true) {
			cout << c << " " << r << "\n";
			break;
		}
	}
	return 0;
}
