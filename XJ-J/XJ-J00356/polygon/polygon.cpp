#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n, a[N], ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]) ans++;
	cout << ans;
	return 0;
} 
