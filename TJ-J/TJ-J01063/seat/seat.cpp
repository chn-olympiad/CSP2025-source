#include<bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n ,m;
	cin >> n >> m;
	vector<int> a;
	int p, l, c, r;
	cin >> p;
	
	a.push_back(-1);
	a.push_back(p);
	for (int i = 2;i <= n*m;i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	
	sort(a.begin() + 1, a.end() + 1, cmp);
	
	for (int i = 1;i <= n*m;i++) {
		if (p == a[i]) {
			l = i;
			cout << l << endl;
			break;
		}
	}
	
	if ((int(l/n) + 1) % 2 == 0) {
		c = int(l/n) + 1;
		r = n - (l % n) + 1;
	}
	else {
		c = int(l/n) + 1;
		r = l % n;
	}
	cout << c << " " << r;
	return 0;
}
