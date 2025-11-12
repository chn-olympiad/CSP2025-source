#include<iostream>
#include<algorithm>
using namespace std;
int u[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int maxi=0;
	cin>>n>>k;
	cin>>u[1];
	for(int i=2;i<=n;i++)
	{
		cin>>u[i];
		u[i]^=u[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int tot=u[i];
			for(int k=i+1;k<=j;k++)
			{
				tot^=u[k];
			}
			maxi=max(maxi,tot);
		}
	}
	cout<<maxi;
	return 0;
}
