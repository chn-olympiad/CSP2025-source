#include<bits/stdc++.h>
using namespace std;
int t,n,ans,zys,a[100005];
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		zys=0;
		for(int i=1;i<=n;i++)
		{
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[i]=max(a1,max(a2,a3));
		}
		sort(a+1,a+n+1);
		for(int i=n;i>n/2;i--)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
