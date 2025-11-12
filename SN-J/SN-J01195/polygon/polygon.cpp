#include <bits/stdc++.h>
using namespace std;
int n,a[5005],cha=1,ans,t[5005],cnt;
void dfs(int now)
{
	if(now>n)
	{
		int y=0,z=0,rjq=0;
		//cout<<cha<<endl;
		for(int i=1;i<=n;i++)
		{
			y+=t[i];
			if(t[i]!=0)
			{
				z++;
			}
			if(t[i]==0)
			{
				rjq=i-1;
				break;
			}
		}
		if(z<3)
		{
			return;
		}
		if(y>2*t[rjq])
		{
			cnt++;
		}
		//cout<<endl;
		return;
	}
	t[cha]=a[now];
	cha++;
	dfs(now+1);
	t[cha]=0;
	cha--;
	dfs(now+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout<<cnt;
	return 0;
}
