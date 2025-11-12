#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,b,h,l,k,a[105];
signed main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){ cin >> a[i];}
	b = a[1];
	sort(a+1,a+n*m+1);
	k = lower_bound(a+1,a+n*m+1,b)-a;
	k = n*m-k+1;
	if(k%n==0) l = k / n;
	else l = k / n + 1;
	if(l%2==1){
		if(k%n==0) h = n;
		else h = k%n;
	}
	else{
		if(k%n==0) h = 1;
		else h=n-k%n+1;
	}
	cout << l << " " << h << "\n";
	return 0;
}

