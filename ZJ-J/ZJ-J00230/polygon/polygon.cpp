#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int n,a[5005],mod=998244353,ecm[5005],s=1,wsx;
priority_queue<pair<int,int>> q;
map<int,int> mp,mc;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ecm[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ecm[i]=ecm[i-1]*2%mod;
	}
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		cout<<(ecm[n]-(1+n+(n-1)*n/2)%mod+mod)%mod;
		return 0;
	}
	q.push({0,1});
	for(int i=1;i<=n;i++)
	{
		int p=0,x=q.size();
		while(!q.empty())
		{
			mp[p]=q.top().first;
			mc[q.top().first]=q.top().second;
			if(q.top().first>a[i])
			{
				wsx+=q.top().second;
				wsx%=mod;
			}
			if(mc[q.top().first+a[i]]>0)
			{
				mc[q.top().first+a[i]]+=q.top().second;
			}
			else
			{
				mc[q.top().first+a[i]]=q.top().second;
				mp[x++]=q.top().first+a[i];
			}
			p++;
			q.pop();
		}
		for(int i=0;i<x;i++)
		{
			q.push({mp[i],mc[mp[i]]});
		}
	}
	cout<<wsx;
	return 0;
}
