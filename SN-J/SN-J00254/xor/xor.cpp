#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
long long k;
long long a[500005];
int n,ans=0,l=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i];
		if(x==k)
		{
			ans++;
			l=i+1;
			continue;
		}
		for(int j=i-1;j>=l;j--)
		{
			x^=a[j];
			if(x==k)
			{
				ans++;
				l=i+1;
				break;
			}
		}		
 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
