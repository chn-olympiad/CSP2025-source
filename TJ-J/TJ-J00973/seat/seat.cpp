#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[105];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+1+n*m);
	int p=lower_bound(a+1,a+1+n*m,tmp)-a,ln;
	p=n*m-p+1;
	if(((p-1)/n+1)%2)ln=(p-1)%n+1;
	else ln=n-p%n+1;
	cout<<(p-1)/n+1<<" "<<ln;
	return 0;
}
