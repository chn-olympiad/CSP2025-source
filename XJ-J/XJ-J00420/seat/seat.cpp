#include <bits/stdc++.h>
using namespace std;
int a[1001];
int p[1001][1001];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int x = a[1];
	//cout << x << endl;
	sort(a + 1,a + 1 + n * m,greater<int>());
	
	//cout << endl;
	int c = 0,r = 0;
	int num = 1;
	
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1) {
			for(int j = 1; j <= m; j++) {
				p[j][i] = a[num];
				//cout << p[j][i] << " ";
				if(p[j][i] == x) {
					c = n;
					r = m;
					//break;
				}
				num++;
			}
		} else {
			
			for(int j = m; j >= 1; j--) {
				p[j][i] = a[num];
				//cout << p[j][i] << " ";

				if(p[j][i] == x) {
					c = n;
					r = m;
					//break;
				}
				num++;
			}
		}

		
	}
	//cout << endl;
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout << p[i][j] << " ";
		}
		cout << endl;
	}*/
	//cout << num;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(p[i][j] == x){
				cout << j << " " << i;
				return 0; 
			}
		}
	}
	//cout << c << " " << r;
	//cout << endl << p[c][r];
	return 0;
}
