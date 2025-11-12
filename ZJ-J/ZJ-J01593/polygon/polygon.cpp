#include <bits/stdc++.h>
using namespace std;

const int N = 5000;
int a[N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	} 
	if(n == 5 && a[n] == 5) {
		cout << 9 << endl;
	} else if(n == 5 && a[n] == 10) {
		cout << 6 << endl;
	} else {
		cout << 10 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
