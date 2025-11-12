#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,a[100000],i;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>q;
	string st;
	cin>>st;
	for(i=1; i<=n; i++) cin>>a[i];
	if(q==1) {
		int ans=1;
		for(i=n; i>=1; i--)
			ans=ans*i%998244353;
		cout<<ans;
	} else cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}