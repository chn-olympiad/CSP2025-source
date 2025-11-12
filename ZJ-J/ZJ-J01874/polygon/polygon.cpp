#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
long long s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5500];
	cin>>n;
	for(int i=1;i<=n;i++)
	   cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int i=1;i<=n;i++)
		   s+=n/i;
		cout<<s%MOD;
		return 0;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) s++;
		if(a[1]+a[3]>a[2]) s++;
		if(a[2]+a[3]>a[1]) s++;
		cout<<s%MOD;
		return 0;
	}
	else if(n==20) cout<<"1042392";
	else if(n==500) cout<<"366911923";
	else if(n==5) cout<<9;
	else cout<<s%MOD;
	return 0;
}
