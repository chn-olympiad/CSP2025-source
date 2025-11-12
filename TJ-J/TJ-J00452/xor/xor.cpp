#include <bits/stdc++.h>
using namespace std;
int a[500000]={0};
bool b[500000]={0};
int main ()
{
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	long long n,k,g=0;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
		cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			int q;
			if (b[i]!=1 && i==j)
				q=a[i];
			else if (b[i]!=1 && i!=j)
				q=a[i];
			else
				q=k+1;
			if (i!=j)
			{
				for (int z=i+1;z<=j;z++)
				{
					if (b[z]==1)
					{
						q=k+1;
						break;
					}
					q^=a[z];
				}
			}
			if (q==k)
			{
				g++;
				cout << endl;
				for (int z=i;z<=j;z++)
					b[z]=1;
			}
		}
	}
	cout << g;
	return 0;
}
