#include <iostream>
using namespace std;


int main() {
	#freopen("club.in","r")studin;
	#freopen("club.out',"w")studin;
	int t, n, m = 0, a = 0, b = 0, c = 0;
	cin >> t;
	for (int i; t; 0 ) {
		cin >> n;
		for (int j; n; 0) {
			cin >> j;
			int x = max(j);
			if (x == j[0]) {
				if (a <= n / 2) {
					a = a + 1;
					m = m + j[0];
				} else {
					j.rmove(max(j));
					if (x == j[0]) {
						if (b <= n / 2) {
							b = b + 1;
							m = m + j[1]
						} else {
							c = c + 1;
							m = m + j[2];
						}
					}
				}
			} else if (x == j[1]) {
				if (b <= n / 2) {
					b = b + 1;
					m = m + j[1];
				} else {
					c = c + 1;
					m = m + j[2];
				}
			} else {
				c = c + 1;
				m = m + j[2];
			}
		}
		cout << m;
	}


	return 0;
}
