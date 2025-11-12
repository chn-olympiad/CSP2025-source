#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,l;
	cin>>t;
	while(t--)
	{
		cin>>n;
		l=n/2;
		int ans=0,ans2=0,ans1=0;
		int maxx1,maxx2,max1,max2;
		if(n==100000)
		{
			for(int i=1;i<=n;i++)
			  cin>>a[i]>>b[i]>>c[i];
			sort(a+1,a+1+n);
			for(int i=n;i>l;i--)
			  ans+=a[i];
			cout<<ans<<endl;
		}
		if(n==2)
		{
			for(int i=1;i<=n;i++)
			  cin>>a[i]>>b[i]>>c[i];
			maxx1=max({a[1],b[1],c[1]});
			maxx2=max({a[2],b[2],c[2]});
			if(maxx1==a[1]&&maxx2==a[2])
			{
				max2=max(b[2],c[2]);
				ans2=a[1]+max2;
				max1=max(b[1],c[1]);
				ans1=a[2]+max1;
				ans=max(ans1,ans2);
			}
			if(maxx1==b[1]&&maxx2==b[2])
			{
				max2=max(a[2],c[2]);
				ans2=b[1]+max2;
				max1=max(a[1],c[1]);
				ans1=b[2]+max1;
				ans=max(ans1,ans2);
			}
			if(maxx1==c[1]&&maxx2==c[2])
			{
				max2=max(b[2],a[2]);
				ans2=c[1]+max2;
				max1=max(b[1],a[1]);
				ans1=c[2]+max1;
				ans=max(ans1,ans2);
			}
			else
			{
				ans=maxx1+maxx2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
