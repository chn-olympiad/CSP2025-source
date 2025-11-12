#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
const int N=5e3+5;
int n,a[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]+a[2]>2*max(a[1],a[2]))ans++;
	if(a[1]+a[3]>2*max(a[1],a[3]))ans++;
	if(a[2]+a[3]>2*max(a[2],a[3]))ans++;
	if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))ans++;
	
	cout<<ans%mod;
	return 0;
}
