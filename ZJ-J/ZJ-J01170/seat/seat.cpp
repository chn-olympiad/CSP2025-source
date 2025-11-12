#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n,m,a,b,ans=1,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> a;
	for (int i = 1;i < n*m;i++){
		cin >> b;
		ans += (b>a);
	}
	x = ans/n;
	y = ans-x*n;
	if (x % 2 == 0){
		if (y == 0)	cout << x << " 1";
		else cout << x+1 << " " << y;
	}
	else{
		if (y == 0) cout << x << " " << n;
		else cout << x+1 << " " << n-y+1;
	}
	return 0;
}
