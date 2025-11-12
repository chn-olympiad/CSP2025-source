#include<bits/stdc++.h>
using namespace std;
long long ans,sum,ai,n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>ai;
		if(i==1)
		{
			ans=ai;
		}
		else
		{
			if(ai>ans)sum++;
		}
	}
	cout<<sum/n+1<<" ";
	if((sum/n)%2==0)cout<<sum%n+1<<endl;
	else cout<<n-sum%n;
	return 0;
}
