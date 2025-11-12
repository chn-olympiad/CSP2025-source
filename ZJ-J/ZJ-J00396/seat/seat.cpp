#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int hang, lie;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> hang >> lie;
	int y = hang * lie;
	int a[y+1];
	for(int i = 1; i <= y; i++) {
		cin >> a[i];
	}
	int b = a[1];
	sort(a+1,a+y+1,cmp);
	int mi;
	for(int i = 1; i <= y; i++) {
		if(a[i] == b) mi = i;
	}
	int h, l;
	l = mi / hang;
	if (mi % hang != 0) {
		l++;
	}
	int qwq = mi % (hang*(l-1));
	if(l % 2 != 0) {
		h = qwq;
	}
	if(l % 2 == 0){
		if(qwq == 0) {
			h = 1;
		}
		else {
			h = hang - qwq + 1;
		}
	}
	cout << l << " " << h << '\n';
	return 0;
}

