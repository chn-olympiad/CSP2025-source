#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,s,a[500004],sum;
signed main()
{
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	if(k==0&&s==n)
	{
		cout<<n/2;
	}
	else if(k<=1)
	{
		if(k==0)
			for(int i=2;i<=n;i++)
				if(a[i]==a[i-1])
					ans++,i+=2;
		else
			for(int i=2;i<=n;i++)
				if(a[i]!=a[i-1])	
					ans++,i+=2;
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(sum==0)
				sum=a[i];
			else if(sum!=k)
				sum=sum^a[i];
			else
			{
				sum=0;
				ans++;
			}
		}
		cout<<ans;
	}
 	return 0;
}