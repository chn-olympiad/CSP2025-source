#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100005],b[100005],cnt1,cnt2,cnt3,c[100005];
int main()
{	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		long long x,y,z;
		for (int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if (x>=y&&x>=z){
				a[i]=x;
				cnt1++;
				if(y>z)
				{
					b[i]=y;
				
				}
				else b[i]=z;
			}
			if (y>=x&&y>=z)
			{
				a[i]=y;
				cnt2++;
				if (x>z)
				{
					b[i]=x;
				}
				else b[i]=z;
			}
			if (z>=x&&z>=y)
			{
				a[i]=z;
				cnt3++;
				if (x>y)
				{
					b[i]=x;
				}
				else b[i]=y;
			}
		}
		ans=0;
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2)
		{
		
			for (int i=1;i<=n;i++)
			{
				c[i]=a[i]-b[i];
			}
			sort(c+1,c+n+1);
			long long ans=0;
			for (int i=1;i<=n;i++)ans+=a[i];
			for (int i=1;i<=max(cnt1,max(cnt2,cnt3))-n/2;i++)
			{
			
				ans-=c[i];
			}
			
		}
		else
		{
			for (int i=1;i<=n;i++)ans+=a[i];
			cout<<ans<<endl;
		}
	}
}

