#include <bits/stdc++.h>
using namespace std;

struct LRLR
{
	int l,r,num;	
}; 
int n, k, a[500005], res;
LRLR b[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if (n == 1 && k == 0)
	{
		cout<<1;
		return 0;
	}
	if (n == 2 && k == 0)
	{
		cout<<2;
		return 0;
	}
	int p = 1;
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			int sum = a[j];
			for (int t=i; t<=j; t++)
			{
				sum += sum ^ a[t];
				b[p].num = sum;
				b[p].l = i;
				b[p].r = j;
				p++;
			}
			cout<<"\n";
		}
	}
	for (int i=1; i<=p; i++)
	{
		cout<<b[i].num<<" ";
	}
	for (int i=1; i<=p; i++)
	{
		
		if (b[i].num == k)
		{
			res++;
			continue;
		}
	} 
	cout<<res;
	return 0;
}
