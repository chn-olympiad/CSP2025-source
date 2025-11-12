#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		sort(a[i]+1,a[n*m]+n*m+1);
	}
	for(int i=1;i<=n*m;i++){
		cout << n/m << " " << n;
	}
	return 0;
}
