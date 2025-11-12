#include<bits/stdc++.h> 
using namespace std;
int n,a[5005],ans=0;
int main()
{
	freopen("oplygon.in","r",stdin);
	freopen("oplygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int l=lower_bound(a+1,a+1+n,a[i]+a[j])-a;
			ans+=l-1;
		}
	}
	cout<<ans;
}
