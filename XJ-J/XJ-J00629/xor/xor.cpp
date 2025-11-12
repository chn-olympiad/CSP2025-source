#include<bits/stdc++.h>
using namespace std;

long long int a[500005],s,n,k,ans;

int main()
{
	freopen("xor6.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,x; bool f;
	cin >> n >> k;
	for (i=1; i<=n; i++)
		cin >> a[i];
	for (i=1; i<=n; i++)
	{
		f=false; s=a[i];
		for (j=i; j<=n; j++)
		{
			if (j!=i)
				s^=a[j];
			if (s==k)
			{
				ans++;
			}
		}
		if (f)
			i+=j;
	}
	return 0;
}
