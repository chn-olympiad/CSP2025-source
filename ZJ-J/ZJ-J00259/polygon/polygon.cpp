#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5005];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	bool yang=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			yang=false;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(n<=3)
	{
		if(a[1]+a[2]>a[3])	cout<<1;
		else	cout<<0;
	}
	if(yang)
	{
		long long ans=0;
		int cnt=1;
		while(n--&&n>=3)
		{
			ans+=cnt;
			cnt++;
		}
		cout<<ans%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}