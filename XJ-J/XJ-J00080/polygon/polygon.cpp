#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = 0;
	maxn = max(a[1],a[2]);
	if (n < 3)
	    cout << 0;
	else if (n == 3 && (a[1]+a[2]+a[3] > 2*max(maxn,a[3])))
	    cout << 1;
	else
	    cout << 0;
	return 0;
}
