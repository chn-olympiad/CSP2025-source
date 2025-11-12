#include<bits/stdc++.h>
using namespace std;
long long n,k,l,x,a[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(a[1]==k) f[1]=1,l=1;
	else f[1]=0,l=0;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=i;j>=l+1;j--)
		{
			if(j==i) x=a[j];
			else x^=a[j];
			if(x==k)
			{
				l=i;
				f[i]++;
				break;
			}
		}
	}
	cout<<f[n];
	return 0;
}