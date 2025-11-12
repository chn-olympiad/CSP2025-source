#include<bits/stdc++.h>
using namespace std;
int a[101] = {};
int n, m;
int j, r;
int x = 1, y = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> r;
	++a[r];
	for(int i = 1;i < n * m;++i){
		cin >> j;
		++a[j];
	}
	for(int k = 100;k > r;--k){
		if (a[k] == 0) continue;
		if (y % 2 == 1){
			if (x < n) ++x;
			else ++y;
		}
		else {
			if (x > 1) --x;
			else ++y;
		}
	}
	cout << y << " " << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
