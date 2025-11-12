#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, a[N], ans, x, y;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans=0;
	    for(int i=1; i<=n; i++){
			cin >> a[i] >> x >> y;
	    }
	    sort(a+1,a+1+n);
	    reverse(a+1,a+1+n);
	    for(int i=1; i<=n/2; i++){
		    ans+=a[i];
	    }
	    cout << ans << '\n';
	}
	return 0;
}
