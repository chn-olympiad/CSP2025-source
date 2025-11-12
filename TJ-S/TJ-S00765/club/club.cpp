#include <bits/stdc++.h>
using namespace std;
bool cmp(int p,int q)
{
	return p>q;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		int n,a[100005],b[100005],c[100005],x,ans=0;
		bool f1=0,f2=0;
		cin >> n;
		for(int j=1;j<=n;j++)
		{
			cin >> a[j] >> b[j] >> c[j];
			if(b[j]!=0)
			{
				f1=1;
			}
			if(c[j]!=0)
			{
				f2=1;
			}
		}
		if(n==2)
		{
			ans=max(ans,a[1]+b[2]);
			ans=max(ans,a[1]+c[2]);
			ans=max(ans,b[1]+a[2]);
			ans=max(ans,b[1]+c[2]);
			ans=max(ans,c[1]+a[2]);
			ans=max(ans,c[1]+b[2]);
			cout << ans << endl;
		}
		else if(n==4)
		{
			ans=max(ans,a[1]+a[2]+b[3]+b[4]);
			ans=max(ans,a[1]+a[2]+b[3]+c[4]);
			ans=max(ans,a[1]+a[2]+c[3]+b[4]);
			ans=max(ans,a[1]+a[2]+c[3]+c[4]);
			ans=max(ans,a[1]+b[2]+a[3]+b[4]);
			ans=max(ans,a[1]+b[2]+a[3]+c[4]);
			ans=max(ans,a[1]+b[2]+b[3]+a[4]);
			ans=max(ans,a[1]+b[2]+b[3]+c[4]);
			ans=max(ans,a[1]+b[2]+c[3]+a[4]);
			ans=max(ans,a[1]+b[2]+c[3]+b[4]);
			ans=max(ans,a[1]+b[2]+c[3]+c[4]);
			ans=max(ans,a[1]+c[2]+a[3]+b[4]);
			ans=max(ans,a[1]+c[2]+c[3]+c[4]);
			ans=max(ans,a[1]+c[2]+b[3]+a[4]);
			ans=max(ans,a[1]+c[2]+b[3]+b[4]);
			ans=max(ans,a[1]+c[2]+b[3]+c[4]);
			ans=max(ans,a[1]+c[2]+c[3]+a[4]);
			ans=max(ans,a[1]+c[2]+c[3]+b[4]);
			ans=max(ans,b[1]+a[2]+a[3]+b[4]);
			ans=max(ans,b[1]+a[2]+a[3]+c[4]);
			ans=max(ans,b[1]+a[2]+b[3]+a[4]);
			ans=max(ans,b[1]+a[2]+b[3]+c[4]);
			ans=max(ans,b[1]+a[2]+c[3]+a[4]);
			ans=max(ans,b[1]+a[2]+c[3]+b[4]);
			ans=max(ans,b[1]+a[2]+c[3]+c[4]);
			ans=max(ans,b[1]+b[2]+a[3]+a[4]);
			ans=max(ans,b[1]+b[2]+a[3]+c[4]);
			ans=max(ans,b[1]+b[2]+c[3]+a[4]);
			ans=max(ans,b[1]+b[2]+c[3]+c[4]);
			ans=max(ans,b[1]+c[2]+a[3]+a[4]);
			ans=max(ans,b[1]+c[2]+a[3]+b[4]);
			ans=max(ans,b[1]+c[2]+a[3]+c[4]);
			ans=max(ans,b[1]+c[2]+b[3]+a[4]);
			ans=max(ans,b[1]+c[2]+b[3]+c[4]);
			ans=max(ans,b[1]+c[2]+c[3]+a[4]);
			ans=max(ans,b[1]+c[2]+c[3]+b[4]);
			ans=max(ans,c[1]+a[2]+a[3]+b[4]);
			ans=max(ans,c[1]+a[2]+a[3]+c[4]);
			ans=max(ans,c[1]+a[2]+b[3]+a[4]);
			ans=max(ans,c[1]+a[2]+b[3]+b[4]);
			ans=max(ans,c[1]+a[2]+b[3]+c[4]);
			ans=max(ans,c[1]+a[2]+c[3]+a[4]);
			ans=max(ans,c[1]+a[2]+c[3]+b[4]);
			ans=max(ans,c[1]+b[2]+a[3]+a[4]);
			ans=max(ans,c[1]+b[2]+a[3]+b[4]);
			ans=max(ans,c[1]+b[2]+a[3]+c[4]);
			ans=max(ans,c[1]+b[2]+b[3]+a[4]);
			ans=max(ans,c[1]+b[2]+b[3]+c[4]);
			ans=max(ans,c[1]+b[2]+c[3]+a[4]);
			ans=max(ans,c[1]+b[2]+c[3]+b[4]);
			ans=max(ans,c[1]+c[2]+a[3]+a[4]);
			ans=max(ans,c[1]+c[2]+a[3]+b[4]);
			ans=max(ans,c[1]+c[2]+b[3]+a[4]);
			ans=max(ans,c[1]+c[2]+b[3]+b[4]);
			cout << ans << endl;
		}
		else if(f1==0&&f2==0)
		{
			sort(a+1,a+n+1,cmp);
			for(int j=1;j<=n/2;j++)
			{
				ans+=a[j];
			}
			cout << ans << endl;
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				x+=a[j];
			}
			cout << x << endl;
		}
	}
}
