#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],ans=1,cnt=3;
int main()
{
	freopen("playgon.in","r",stdin);
	freopen("playgon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<n;i++)
	{
		ans+=cnt;
		cnt*=2;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}