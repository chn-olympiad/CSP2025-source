#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a[1010],n,k,max=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int s=0,b=0;
		for(int j=i;j<=n;j++)
		{
			s=s^a[j];
			if(a[j]==0)
			{
				b++;
			}
			if(s==k)
			{
				cout<<j-i+1-b<<endl;
				if(max<j-i+1-b)
				{
					max=j-i+1-b;
				}
				break;
			}
		}
	}
	cout<<max;
	return 0;
}
