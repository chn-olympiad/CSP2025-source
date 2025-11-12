#include<bits/stdc++.h>
using namespace std;
int t;
int compare(int x,int y) {
	if (x>=y) {
		return x;
	}
	else {
		return y;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for (int w = 0;w<t;w++) {
		int n,p[5][100005],ans = 0;
		int a = 0,b = 0,c = 0;
		scanf("%d",&n);
		for (int i = 1;i<=n;i++) {
			for (int j = 1;j<=3;j++) {
				cin >> p[i][j];
			}
		}
		for (int i = 1;i<=n;i++) {
			int f;
			for (int j = 1;j<=3;j++) {
				int m;
				if (j == 1) {
					m = p[i][j];
					f = j;
				}
				else {
					if (p[i][j] > m) {
						m = p[i][j];
						f = j;
					}
				}
				
			}
			ans += p[i][f];
			if (f == 1) {
				a++;
			}
			else if (f == 2) {
				b++;
			}
			else {
				c++;
			}
		}
		if (a > n/2 || b > n/2 || c > n/2) {
			for (int j = 0;j < 100000000000;j++) {
			if (a > n/2) {
				int s;
				for (int i = 1;i<=n;i++) {
					if (i == 1) {
						s = p[i][1] - compare(p[i][2],p[i][3]);
					}
					else {
						if (p[i][1] - compare(p[i][2],p[i][3]) < s) {
							s = p[i][1] - compare(p[i][2],p[i][3]);
						}
					}
				}
				a--;
				ans -= s;
			}
			else if (b > n/2) {
				int s;
				for (int i = 1;i<=n;i++) {
					if (i == 1) {
						s = p[i][2] - compare(p[i][1],p[i][3]);
					}
					else {
						if (p[i][2] - compare(p[i][1],p[i][3]) < s) {
							s = p[i][2] - compare(p[i][1],p[i][3]);
						}
					}
				}
				b--;
				ans -= s;
			}
			else if (c > n/2) {
				int s;
				for (int i = 1;i<=n;i++) {
					if (i == 1) {
						s = p[i][3] - compare(p[i][2],p[i][1]);
					}
					else {
						if (p[i][3] - compare(p[i][2],p[i][1]) < s) {
							s = p[i][3] - compare(p[i][2],p[i][1]);
						}
					}
				}
				c--;
				ans -= s;
			}
			else {
				cout << ans << endl;
				break;
			}	
		}

		}
		else {
			cout << ans << endl;
				
	}
		
	}
	return 0;
} 
