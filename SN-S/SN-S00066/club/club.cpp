#include <bits/stdc++.h>
using namespace std;
int a1[10010],a2[10010],a3[10010],a[10101];
long long s=0,m1,m2,m3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int m=n/2;
		if(n==2)
		{
			s=a1[1]+a2[2];
			if(a1[1]+a3[2]>s) s=a1[1]+a3[2];
			if(a2[1]+a1[2]>s) s=a2[1]+a1[2];
			if(a2[1]+a3[2]>s) s=a2[1]+a3[2];
			if(a3[1]+a1[2]>s) s=a3[1]+a1[2];
			if(a3[1]+a2[2]>s) s=a3[1]+a2[2];
			cout<<s;
			
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]>=a2[j]&&a1[j]>=a3[j])
			{
				a[j]=a1[j];
				m1++;
			}
			if(a2[j]>a1[j]&&a2[j]>=a3[j])
			{
				a[j]=a2[j];
				m2++;
			}
			if(a3[j]>a1[j]&&a3[j]>a2[j])
			{
				a[j]=a3[j];
				m3++;
			}
				
		}
	
		if(m1<=m&&m2<=m)
		{
			if(m3<=m)
			{
				for(int j=1;j<=n;j++)
					s+=a[j];
					
			}
			else
			{
				sort(a+1,a+n+1);
				for(int j=n;j>=m;j--)
					s+=a[j];
					
			} 
		}
		else
		{
			sort(a+1,a+n+1);
			for(int j=n;j>m;j--)
				s+=a[j];
					
			 
		}
	
		cout<<s<<endl;
	}
	return 0;
}
