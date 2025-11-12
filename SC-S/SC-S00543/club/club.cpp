#include<bits/stdc++.h>
using namespace std;

int t,n,a[100005];
long long ans=0;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		if(n==2)
		{
			int a[4],b[4],ans=0;
			cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
			for(int j=1;j<=3;j++)
				for(int k=1;k<=3;k++)
					if(j!=k)
						ans=max(ans,a[j]+b[k]);
			cout<<ans<<endl;
			continue;
		}
		int x,y;
		for(int j=1;j<=n;j++)
			cin>>a[j]>>x>>y;
		sort(a+1,a+n+1);
		for(int j=n/2+1;j<=n;j++)
			ans+=a[j];
		cout<<ans<<endl;
		continue;
		
	}
	return 0;
}