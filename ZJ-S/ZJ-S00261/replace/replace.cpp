#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200010;
ll n,m,ans;
string a[N],b[N],x,y;
string front,middle,back,all;
bool check(ll u,ll id)
{
	if(u+(ll)a[id].size()-1<=x.size()-1)
	{
		front=x.substr(0,u);
		middle=x.substr(u,(ll)a[id].size());
		back=x.substr(u+(ll)a[id].size(),(ll)x.size()-u-(ll)a[id].size());
		if(middle!=a[id])
		{
			return false;
		}
		middle=b[id];
		all=front+middle+back;
		return all==y;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(m--)
	{
		ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=(ll)x.size()-1;j++)
			{
				if(check(j,i))
				{
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}