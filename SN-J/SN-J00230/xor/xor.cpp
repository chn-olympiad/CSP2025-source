#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;)
	{
		for(int j=i;j<=n;j++)
		{
			int cnt=0;
			for(int l=i;l<=j;l++)
			{
				cnt^=a[l];
			}
			if(cnt==k)
			{
				ans++;
				i=j+1;
				break;
			}
		}
	}
	cout<<ans;
}
