#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[100100],l,cnt,b[100100],sum;
main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	

	for(int i=1;i<=n;i++)
	{
		sum=a[i];
		for(int j=i;j<=n;j++)
		{
			if(j!=i)
			{
				sum=((sum)^(a[j]));
			}
			l++;
			if(sum==m)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
}












