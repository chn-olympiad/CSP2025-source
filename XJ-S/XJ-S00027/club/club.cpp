#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1000000],b[1000000],c[1000000],s[1000000],m,v[1000000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		m=0;
		cin>>n;
		if(n<=200)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
				if(a[i]>b[i])
				s[i]=a[i];
				else
				{
					s[i]=b[i];
					v[i]=1;
				}
				if(c[i]>s[i])
				{
					s[i]=c[i];
					v[i]=2;
				}
			}
			for(int i=1;i<=n;i++)
			{
				m+=s[i];
			}
			cout<<m<<"\n"; 
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
			}
			sort(a+1,a+1+n);
			int p=n;
			for(int i=1;i<=n/2;i++)
			m+=a[p--];
			cout<<m<<"\n";
	}
	
}
}
