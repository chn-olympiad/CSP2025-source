#include<bits/stdc++.h>

using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100001],ans=0,cnt=0;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
		cnt+=a[i];
	}
	if(cnt>ans*2)
	{
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
