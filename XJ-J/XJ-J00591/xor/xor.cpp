#include <bits/stdc++.h>
using namespace std;
int xorn(int n[],int l,int r)
{
	int ret = n[l];
	for (int i=l+1;i<=r;i++)
	{
		ret ^= n[i];
	}
	return ret;
} 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010];
	cin >> n >> k;
	int isA = 1,isB=1;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
		if (a[i] != 1)
		{
			isA=0;
			if (a[i] != 0) isB=0;
		}
	}
//	cout << isA << " " << isB;
	if (isA)
	{
		int ans = n/2;
		cout << ans;
	}
	return 0;
} 
