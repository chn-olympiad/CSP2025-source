#include<bits/stdc++.h>
#define int long long
using namespace std;
int mp[105],a[105],cnt,n,m,sum;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>mp[i];
		a[i]=mp[i];
	}
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i)
		if(a[i]==mp[1])
		{
			cnt=i;
			break;
		}
	sum=cnt/n;
	if(sum%2==1)
	{
		if(cnt%n==0) return cout<<sum<<" "<<n,0;
		else if(cnt%n!=0) return cout<<sum+1<<" "<<n-(cnt-(sum*n))+1,0;
	}
	else if(sum%2==0)
	{
		if(cnt%n==0) return cout<<sum<<" "<<1,0;
		else if(cnt%n!=0) return cout<<sum+1<<" "<<cnt-(sum*n),0;
	}
	return 0;
}
