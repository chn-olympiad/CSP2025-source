#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,a[500010],s[500010],ss,ma=-1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]==1)ss++;
	}
	if(k==1)
	{
		cout<<ss;
	}
	else if(k==0)cout<<n-ss;
	else
	{
		for(int i=1;i<=n;i++)
		{
			ans=0;
			for(int l=i;l<=n;l++)
			{
				for(int r=l;r<=n;r++)
				{
					if((s[r]^s[l-1])==k)
					{
						l=r;
						ans++;
						break;
					}
				}
			}
			ma=max(ma,ans);
		}
		cout<<ma;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}