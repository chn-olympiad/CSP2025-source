#include <iostream>
using namespace std;
int b[1001];
int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[m][n];
	bool flag = true;
	for (int i = 0; i < m*n; i++){
		cin >> b[i];
	}
	int d = b[0];
	while (flag){
		int aa = 0;
		for (int i = 1; i < m*n; i++){
			int c = 0;
			if (b[i] > b[i-1]){
				c = b[i];
				b[i] = b[i-1];
				b[i-1] = c;
				aa++;
			}
		}
		if (aa == 0){
			flag = false;
		}
	}
	for (int i = 0; i < m; i++){
		if (i % 2 == 0){
			for (int j = 0; j < n; j++){
				a[i][j] = b[(i/2)*m+j];
			}
		}
		else {
			for (int k = n-1; k >= 0; k--){
				a[i][k] = b[2+(i/2)*m+k];
			}
		}
	}
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (a[i][j] == d){
				cout << i+1 << " " << j+1;
			}
		}
	}
	
	return 0;
}
