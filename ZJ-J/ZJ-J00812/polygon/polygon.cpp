#include<bits/stdc++.h>
using namespace std;
int a[5010],t[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		t[i]=a[i]+t[i-1];
	}
	for(int i=3;i<=n;i++)
	{
		for(int l=1;l<=n-i+1;l++)
		{
			int r=l+i-1;
			if(t[r]-t[l-1]>a[r]*2)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
