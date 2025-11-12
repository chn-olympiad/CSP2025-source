#include<bits/stdc++.h>
using namespace std;
int n,m,a[500002],ans,p;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==m)
		{
			ans++;
			p=0;
		}
		else
		{
			if(m==0)
			{
				p++;
				if(p==2)
				{
					p=0;
					ans++;
				}
			}
			
			
		}
	}
	cout<<ans;
	return 0;
}
