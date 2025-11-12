#include<bits/stdc++.h>
using namespace std;

int n, k, a[200005], f[200005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i = 0; i<n; i++)
	{
		cin>>a[i];
		if(i==0) f[0]=a[0];
		else f[i]=f[i-1]+a[i];
	}
//	if(f[n-1]==n && k==0) cout<<n;
	if(k==1)
	{
		cout<<f[n-1];
	}
	else 
	{
		int temp=0;
		for(int i = 0; i<n-1; i++)
		{
			if(a[i]==1 && a[i+1]==1)
			{
				temp++;
				i++;
			}
		}
		cout<<n-f[n-1]+temp;
	}
	return 0;
}
