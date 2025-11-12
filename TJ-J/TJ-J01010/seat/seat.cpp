#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long a=0; 
	long long cnt=1;
	for(long long i=1;i<=n*m;i++)
	{
		long long a1;
		cin >> a1;
		if(i==1) a=a1;
		else
		{
			if(a1>a) cnt++;
		}
	}
	long long ans=cnt/n,ans1=0;//ans£ºÁÐ ans1£ºÐÐ 
	if(cnt%n!=0)
	{
		ans++;
	 } 
	if(ans%2!=0)
	{
		if(cnt%n==0) ans1=n;
		else ans1=cnt%n;
		cout << ans<<" "<<ans1;
	}
	else
	{
		if(cnt%n==0) ans1=1;
		else ans1=cnt%n;
		cout << ans<<" "<< n-ans1+1;
	}
	return 0;
}

