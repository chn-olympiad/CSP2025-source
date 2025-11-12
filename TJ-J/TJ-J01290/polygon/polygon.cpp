#include<bits/stdc++.h>
using namespace std;
int n, a[5],b;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("poligon.out","w",stdout);
	cin >> n;
	for (int i = 0;i<n;i++) {
		cin >> a[i];
		if (i == 0) {
			b = a[i];
		}
		if (a[i] > b) {
			b = a[i];
		}
	}
	if (2*b >= a[1] + a[0] + a[2]) {
		cout << '0';
	}
	else {
		cout << '1';
	}
	return 0; 
}
