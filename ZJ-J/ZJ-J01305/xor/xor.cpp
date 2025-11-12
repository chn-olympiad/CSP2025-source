#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int temp;
		cin>>temp;
	}
	int z=0;
	int tn=n;
	for(int i=2;i<=n;i+=2)
	{
		tn=n;
		while(tn>1)
		{
			z++;
			tn-=i;
		}
	}
	cout<<z;
	return 0;
}
