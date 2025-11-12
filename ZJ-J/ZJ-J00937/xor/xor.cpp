# include <bits/stdc++.h>
using namespace std;
int n,x;
int a[1010101];
int ans,m,ne,f;
int main()
{	 		
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
			
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(m^a[i]==x)
			{
				ans++;
				ne=j;
				f=1;
				break;
			}
			m=m^a[j];
		}
		if(f==0)
		{
			continue;
		}
		i=ne;
	}
	cout<<ans;
	return 0;
}