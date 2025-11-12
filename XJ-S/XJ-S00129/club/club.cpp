#include<bits/stdc++.h>
using namespace std;
long long int a[100005],i,n,t,c[100005],b[100005],d,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
		    cin>>a[i]>>b[i]>>d;
		    c[i]=max(a[i],b[i]);
	    }
		sort(c+1,c+1+n,greater<long long int>());
		for(i=1;i<=n/2;i++)
		ans+=c[i];
	}
	cout<<ans<<endl;
	return 0;
}
