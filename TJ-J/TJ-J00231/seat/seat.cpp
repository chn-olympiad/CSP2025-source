#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
	freopen("seat3.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> x >> y;
	int a[x][y];
	for(int i = 0; i < x; i ++) {
		for(int j = 0; j < y; j ++) {
			cin >> a[i][j]; 
		}
	}
	int h = a[0][0];//Ð¡RµÄ³É¼¨
	for(int i = 0; i < x; i ++) {
		for(int j = 1; j < y; j ++) {
			if(a[i][j] > h) {
				
				
			}	 
		}
	}
	return 0;
}
