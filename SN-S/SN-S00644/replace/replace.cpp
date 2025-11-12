#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000],b[100000],c[100000],s[100000],sum,k=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			s[i]=a[i];
		}

		sort(s+1,s+n+1);
		for(int i=n;i>n/2;i--)
		{
			sum+=s[i];
		}
		cout<<sum;
	}
	return 0;
}
