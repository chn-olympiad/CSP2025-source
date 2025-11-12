#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y) {
	return x > y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int arr[a*b];
	for(int n = 0; n<a*b; n++) {
		cin >> arr[n];
	}
	bool flag = true;
	int xb = 1,l = 1;
	int cj = arr[0];
	sort(arr,arr+a*b,cmp);
	int conzhi;
	for(int n = 0; n<a*b; n++) {
		if(arr[n] == cj) {
			conzhi = n+1;
			break;
		}
	}
//	cout << "conzhi=" << conzhi << endl;
	l = ceil((conzhi+0.0000)/a);
//	cout << "conzhi/a="<<conzhi/a << endl;
//	cout << "ceil="<<ceil((conzhi+0.0000)/a) << endl;
	if(l % 2 == 0) {
		xb = conzhi - (l-1)*a + 1;
	} else {
		xb = (conzhi-(l-1)*a);
	}
	cout << l << " " << xb;
	return 0;
}

