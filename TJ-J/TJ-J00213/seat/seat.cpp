#include<bits/stdc++.h>
using namespace std;

int a[110];
bool cmp(int x, int y){return x > y;}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, r, thisintissofun,nn;
	cin >> n >> m;
	nn = n * m;
	for (int i = 1; i <= nn; i++) cin >> a[i];
	r = a[1];
	sort(a + 1, a + nn + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r){
			thisintissofun = i;
			break;
		}
	}
	int row = (thisintissofun - 1) / n + 1;
	int tiisfmn;
	if (thisintissofun % n == 0) tiisfmn = n;
	else tiisfmn = thisintissofun % n;
	if (row % 2 != 0) cout << row << " " << tiisfmn << endl;
	else cout << row << " " << n - tiisfmn + 1<< endl;
	return 0;
}
