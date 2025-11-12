#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],n;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3) cout<<0;
	if(n==3){
		if(a[1]+a[2]+a[3] > 2*max(a[1],max(a[2],a[3])))
			cout<<1;
	}
	return 0;
}
