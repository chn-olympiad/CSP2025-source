//何侣佟-SN-J00036-西安滨河学校
#include <bits/stdc++.h>
using namespace std;
long long n,m,x,l;
vector<long long> a,sa;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i<n*m; i++) {
		cin >>x;
		a.push_back(x);
	}
	x = a[0];
	sort(a.begin(),a.end());
	for(int i = m*n-1; i>=0; i--) {
		sa.push_back(a[i]);
	}
	for(int i = 0; i<=n*m; i++) {
		if(sa[i] == x) {
			if((i/n)%2 ==0) {
				if((i+1)%n==0) {
					cout << (i/n)+1<<" "<<n;
				} else {
					cout << (i/n)+1<<" "<<(i+1)%n;
				}
			} else {
				cout << (i/n)+1<<" "<<n-(i%n);
			}
		}
	}
	return 0;
}

