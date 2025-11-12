#include <bits/stdc++.h>
using namespace std;

struct stu{
	int gra,hao;
}f[110];

bool cmp(stu u1,stu u2) {
	return u1.gra > u2.gra;
}
int a[11][11];
int dx[2] = {1,-1};
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int num = 1;
	int fang = 0;
	int x = 1, y = 1;
	for (int i = 1; i <= n * m; i ++) {
		cin >> f[i].gra;
	}
	int flag1 = f[1].gra;
	
	sort(f + 1,f + n * m + 1,cmp);
	
	int p;
	for (p = 1; p <= m*n; p ++) {
		if(f[p].gra == flag1) break;
	}
	
	while(num < p) {
		int nx = x + dx[fang];
		a[1][1] = 1;
		if (nx >= 1 && nx <= n && a[nx][y] == 0) {
			x = nx;
			num ++; 
			a[x][y] = 1;
		}
		else {
			num ++;
			fang = (fang + 1) % 2;
			
				y += 1;
			a[x][y] = 1;
		}
	}
	
	cout << y << ' ' << x << '\n';
	return 0;
} 
