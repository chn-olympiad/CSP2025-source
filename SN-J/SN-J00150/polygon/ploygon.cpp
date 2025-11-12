#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("ploygon.in", "r", stdin);
	freopen ("ploygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	if (n == 3){
		if (a[1]+a[2] > a[3])
		    cout << 1;
		else
		    cout << 0;
	}
    return 0;
}
