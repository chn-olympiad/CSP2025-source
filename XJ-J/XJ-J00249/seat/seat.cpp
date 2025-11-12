#include <bits/stdc++.h>
using namespace std;

int n,m,cj=0,h=0,r=0,c=0;
int s[500];

inline void px() {
	for(int i=1; i<=n*m; i++) {
		for(int j=i+1; j<=n*m; j++) {
			if(s[j]>s[j-1]) {
				swap(s[j],s[j-1]);
			}
		}
	}
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++) {
		cin >> s[i];
	}
	cj=s[1];
	px();
	for(int i=1; i<=n*m; i++) {
		if(s[i]==cj) {
			h=i;
			break;
		}
	}
	if(h%n==0) {
		c=h/n;
	} else {
		c=h/n+1;
	}
	if(h%n==0) {
		r=h%n+1;
	} else {
		r=h%n+1;
	}
	cout << c << ' ' << r << endl;
	return 0;
}
