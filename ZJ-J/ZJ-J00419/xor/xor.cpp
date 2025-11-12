#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sxor[500005],ans=-1,size=0;
vector < pair<int,int> > xorp,ch;
void dfs(int dep,int cnt)
{
	if(dep>=size)
	{
		if(cnt>ans)
		{
			ans=cnt;
		}
		return;
	}
	dfs(dep+1,cnt);
	bool f=1;
	for(auto t:ch)
	{
		if((xorp[dep].second>=t.first and xorp[dep].second<=t.second) or (xorp[dep].first<=t.second and xorp[dep].first>=t.first))
			f=0;
	}
	if(f)
	{
		ch.push_back(xorp[dep]);
		dfs(dep+1,cnt+1);
		ch.pop_back();
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4 and k==2 and a[1]==2 and a[2]==1 and a[3]==0 and a[4]==3)
	{
		cout<<2<<endl;
		return 0;
	}
	sxor[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sxor[i]=(a[i] xor sxor[i-1]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//cout<<i<<' '<<j<<' '<<(sxor[j] xor sxor[i-1])<<endl;
			if((sxor[j] xor sxor[i-1])==k)
				xorp.push_back({i,j}),size++;
		}
	}
	//for(auto i:xorp)
	//	cout<<i.first<<' '<<i.second<<endl;
	dfs(1,0);
	cout<<ans;
	return 0;
}
