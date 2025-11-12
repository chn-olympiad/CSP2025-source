#include<bits/stdc++.h>
using namespace std;
long long a[600000],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans%998244353;
	return 0; 
}

 
