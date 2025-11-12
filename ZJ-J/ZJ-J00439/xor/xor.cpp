#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,k;
long long a[N],b[N];
long long ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	long long l=1,r=1;
	while(r<=n)
	{
		long long t=b[r]^b[l-1];
		if(t==k)
		{
			ans++;
			r++;
			l=r;
		}
		else
		{
			r++;
		}
	}
	cout<<ans;
	return 0;
}
