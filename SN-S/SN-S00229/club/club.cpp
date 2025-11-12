#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int a[100000],b[100000],c[100000];
	int x,y,z=0,d=0,e=0,f=0;
	for(int p=0;p<t;p++)
	{
		cin>>n;	
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
	 	    if(a[i]>b[i]&&a[i]>c[i])
			{
				x++;
				d+=a[i];
			}
			else if(b[i]>a[i]&&b[i]>c[i])
			{
				y++;
				e+=b[i];
			}
			else if(c[i]>b[i]&&c[i]>a[i])
			{
				z++;
				f+=c[i];
			}
		}
		if(x<=n/2&&y<=n/2&&z<=n/2)
		{
			cout<<d+e+f<<endl;
			return 0;
		}
		else
		{
			sort(a,a+n);
			int ans=0;
			for(int i=0;i<n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
