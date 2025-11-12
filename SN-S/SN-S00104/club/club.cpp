#include<bits/stdc++.h>
using namespace std;
int a[100005][4],b[100005],v[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,x=0,y=0,z=0,s=0,ji=0,t2;
	long long n,ans=0,maxn;
	cin>>t>>n;
	for(int g=1;g<=t;g++)
	{
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
		
		cin>>a[i][j];
		}
		if(a[i][1]>a[i][2])
		{
		  maxn=a[i][1];}
		else 
		{
		maxn=a[i][2];}
		if(maxn>a[i][3]&&maxn==a[i][2])
		{
		 y++;
		 ans+=maxn;
		}
		if(maxn>a[i][3]&&maxn==a[i][1])
		{
			x++;
			ans+=maxn;
		}
		if(maxn<=a[i][3])
		{
			ans+=a[i][3];
			z++;
		}//meihangzuidazhi
	}



		
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]==0&&a[i][3]==0)
		{
			b[i-1]=a[i][2];
			s++;
			
		}
		if(s==n)
		{
			sort(b,b+n);
			for(int j=n-1;j>=n/2;j--)
			{
				ji+=b[j];
				
				
			}
			cout<<ji;
			return 0;
		}
	}

	cout<<ans<<endl;


	
	}

	return 0;
}
