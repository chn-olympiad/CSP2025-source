#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[100005],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) cnt++;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			int s=0,d=0;
			for(int c=j;c<=j+i-1;c++)
			{
				if(a[c]==0)
				{
					d++;
				}
				else s+=a[c];
			}
			if(s==k&&d==0)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
