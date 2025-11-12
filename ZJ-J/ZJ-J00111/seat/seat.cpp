#include <bits/stdc++.h>
using namespace std;

const int M = 10 * 10 + 10;
int a[M] = {0};
int m, n, h;


int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> h;
	a[0] = h;
	for(int i = 1; i < n * m; i++){
		cin >> a[i];
	}
	sort(a, a + n * m);
	int x = n * m - 1;
	for(int i = 1; i <= m; i++){
		if(i % 2 == 1){
			for(int j = 1; j <= n; j++){
				if(a[x] == h){
					cout << i << " " << j;
					return 0;
				}
				x--;
			}
		} else{
			for(int j = n; j >= 1; j--){
				if(a[x] == h){
					cout << i << " " << j;
					return 0;
				}
				x--;
			}
		}
	}
	return 0;
}
