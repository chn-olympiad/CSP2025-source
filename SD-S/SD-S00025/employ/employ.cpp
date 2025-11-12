#include <bits/stdc++.h>
using namespace std;
long long n,m,a[501],sum=0;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n!=0){
		long long y=n;
		if(y-m+1>=0)sum+=(y-m+1);
		else break;
		y-=(m-1);
	}
	cout<<sum%998244353;
	return 0;
}
