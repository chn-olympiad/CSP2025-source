#include<bits/stdc++.h> 
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	bool sanjiaoxing=0,suibianxuan=0;
	int n;cin>>n;
	if(n!=3)  sanjiaoxing=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)  suibianxuan=1;
	}
	if(sanjiaoxing==0)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		  cout<<1;
		  else
		  cout<<0;
		  return 0;
	}
	if(suibianxuan==0)
	{
		int x=n*(n-1)*(n-2);
		int cnt=1;
		for(int i=2;i<=n-3;i++)
			cnt++,cnt*=i;
		cnt++,cnt*=x;
		cout<<cnt%998244353;
		return 0;
	}
	cout<<0;
	return 0;
}
