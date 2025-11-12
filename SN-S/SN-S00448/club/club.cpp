#include <bits/stdc++.h>
using namespace std;
long long t, n, ans, a[100010], b[100010], c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i=1; i<=t; i++){
		cin >> n;
		for(int j=1; j<=n; j++){
			cin >> a[j] >> b[j] >> c[j];
			ans+=max(a[j],max(b[j],c[j]));
		}
		cout << ans << endl;
	}
	return 0;
}
