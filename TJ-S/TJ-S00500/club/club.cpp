#include <bits/stdc++.h>
using namespace std;

long long c[3][10010][5];
long long d[100];
long long num = 0;

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a = 0;
    int b = 0;

    cin >> a;
    for (int i = 1;i <= a;i++) {
    	cin >> b;

    	for (int j = 1;j <= b; j++) {

    		for (int k = 1;k <= 3;k++) {
    			cin >> c[k][b][i];
			}

		}

		if (c[1][b][i] > c[2][b][i]) {
			swap(c[1][b][i],c[2][b][i]);
		}
        if (c[2][b][i]> c[3][b][i]) {
            swap(c[2][b][i],c[3][b][i]);
		}
        if (c[1][b][i] > c[2][b][i]) {
            swap(c[1][b][i],c[2][b][i]);
		}

		for (int jk = 1;jk <= b; jk++) {
			if (b > 1) {
				num+=c[3][b][i] + c[3][b-1][i];
			}
        	else if (b == 1) {
        		num+=c[3][b][i];
			}
			d[i] = num;
		}
	}
    for (int p = 1; p <= a; p++) {
        cout << d[p] << endl;
    }

    return 0;
}
