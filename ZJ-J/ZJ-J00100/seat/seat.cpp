#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], num;
bool cmp(int xx, int yy){
	return xx > yy;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i=0; i < n*m; i++)  cin >> a[i];
	num = a[0];
	sort(a, a+(n*m), cmp);
	for (int i=0; i < n*m; i++){
		int xx = (i/n) + 1, yy;
		if ( (i/n) % 2 == 1)  yy = n - (i%n);
		else  yy = i%n + 1;
		if (a[i] == num){
			cout << xx << " " << yy;
			break;
		}
	}
	return 0;
}
