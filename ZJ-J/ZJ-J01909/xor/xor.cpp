#include <bits/stdc++.h>
using namespace std;
const int N=1000001,M=1001;
long long n,f[N],k,a[N],ans;
int main ()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);cout.tie (0);
	cin >>n>>k;
	for (int i=1;i<=n;i++) cin >>a[i];
	if (k==0)
	{
		for (int i=1;i<=n;i++) 
		{
			if (a[i]==0) ans++,f[i]=1;
			else if ((a[i]+a[i-1])%2==0&&f[i]==0) ans++,f[i]=f[i-1]=1;
		}
	}
	else if (k==1)
	{
		for (int i=1;i<=n;i++) ans+=a[i];
	}
//	else
//	{
//		
//	}
	cout <<ans;
	return 0;
}
