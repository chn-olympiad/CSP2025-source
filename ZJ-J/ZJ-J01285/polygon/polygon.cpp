#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
void check(int x,int side,int longest,int sum,int cur)
{
	if(side==x)
	{
		if(longest*2<sum)
			ans++;
		return;
	}
	for(int i=cur+1;i<=n;i++)
	{
		check(x,side+1,max(longest,a[i]),sum+a[i],i);
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
		for(int i=3;i<=n;i++)
		{
			check(i,0,0,0,0);
			ans%=998244353;
		}
	cout<<ans;
	return 0;
}

