#include <bits/stdc++.h>
using namespace std;
int main()
{ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long s=0,t,n,a[10001],b[10001],c[10001],d[6];
	cin>>t;
	int tt=t;
	while(t)
	{
		s++;
		cin>>n;
		for(long long i=0;i<n;i++)
		{
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		if(n%3==0)
		{
			for(long long i=0;i<n/3;i++)
			{
				d[s]+=a[i]+b[i]+c[i];
			}
		}
		else if(n%3==1)
		{
			for(long long i=0;i<n/2;i++)
			{
				d[s]+=a[i]+b[i]+c[i];
			}
			d[s]+=a[n/2+1];
		}
		else
		{
			for(long long i=0;i<n/2;i++)
			{
				d[s]+=a[i]+b[i]+c[i];
			}
			d[s]+=a[n/2+1];
			d[s]+=b[n/2+1];
		}
		t--;
	}
	for(int i=1;i<=tt;i++)
	{
		cout<<d[i]<<endl;
	}
	return 0;
}
