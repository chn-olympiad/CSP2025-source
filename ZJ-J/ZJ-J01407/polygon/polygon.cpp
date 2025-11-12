#include<bits/stdc++.h>
using namespace std;
int ans;
int a[5];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	int n=0;
	cin>>n;
	if(n==3)
	{
		int maxn=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxn=max(a[i],maxn);
			sum+=a[i];
			if(sum>2*maxn)
				ans++;
		}
		cout<<ans;
		return 0;	
	}
	else
		cout<<0;
	return 0;
}