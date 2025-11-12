#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,cnt,st,ed;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int t=0,l=1;
	while(l<=n)
	{
		t^=a[l];
		++l;
	}
	st=1;
	while(st<=n)
	{
		ed=2e9;
		for(int j=st;j<=n&&j<ed;j++)
		{
			int v=j,ts=0,flag=0;
			while(ts!=k&&v<=n&&v<ed ||!flag)
			{
				flag=1;
				ts^=a[v];
				v++;
			}
			if(ts==k)
				ed=min(ed,v);
		}
		if(ed!=2e9)
		{
			st=ed;
			ans++;
		}
		else
			break;
	}
	cout<<ans<<"\n";
	return 0;
}