#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	int a=4;
//	int a1=4;
//	int ans=a^a1;
//	cout << ans;
	//freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	long long ans=0;
	long long n,k;
	cin >> n >> k;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	long long cnt=0;
	for(long long i=1;i<=n;i++)
	{
		cnt^=a[i];
		if(cnt==k)
		{
			ans++;
			cnt=0;
		 } 
		
	 } 
	cout << ans;
	return 0;
}

