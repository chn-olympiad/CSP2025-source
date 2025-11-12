#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100086],cnt=0,r=0,c;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(r!=n)
	{
		c=a[r+1];
		for(int i=r+2;i<=n;i++)
		{
			if(c==k)
			{
				r=r+1;
				cnt++;
				break;
			}
			if((c^a[i])==k)
			{
				r=i;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
