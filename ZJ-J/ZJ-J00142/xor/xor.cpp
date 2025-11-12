#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005];
struct node{
	int l,r;
};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	bool flagA=1,flagB=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		if(a[i]!=1) flagA=0;
		if(a[i]>1) flagB=0;
	}
	if(flagA && k==0)
	{
		cout<<n/2<<endl;
		return 0;
	}
	else if(flagB && k<=1)
	{
		int ans=0;
		int last=1;
		for(int i=1;i<=n;i++)
		{
			while(a[i+1]==a[last] && i+1<=n) i++;
			if(a[i]==0 && k==0) ans+=(i-last+1);
			else if(a[i]==1 && k==0) ans+=(i-last+1)/2;
			else if(a[i]==1 && k==1) ans+=(i-last+1);
			last=i+1;
		}
		cout<<ans<<endl;
		return 0;
	}
	else if(n<=1000)
	{
		vector <node> v;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				if((sum[j]^sum[i-1])==k)
				{
//					cout<<i<<' '<<j<<endl;
					v.push_back({i,j});
					break;
				}
		}
//		for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
//		cout<<endl;
//		for(node u:v)
//			cout<<u.l<<' '<<u.r<<endl;
		vector <node> ans;
		ans.clear();
		for(int i=0;i<v.size();i++)
			if(v[i].l>ans[ans.size()-1].r)
			{
				if(i+1<v.size() && v[i+1].r<=v[i].r) continue;
				ans.push_back(v[i]);
			}
		cout<<ans.size()<<endl;
		return 0;
	}
	return 0;
}