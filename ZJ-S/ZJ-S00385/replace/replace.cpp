#include<bits/stdc++.h>
using namespace std;
string fi[1000005],rep[1000005],from,to,rr;
long long n,q,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>fi[i]>>rep[i];
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>from>>to;
		if(from.size()!=to.size())
		{
			cout<<0<<endl;
			continue;
		}
		for(int j=1;j<=n;j++)
		{
			rr=from;
			long long pf=from.find(fi[j]),pt=to.find(rep[j]);
			if(pf!=pt)
			{
				continue;
			}
			if(pf<0||pt<0)
			{
				continue;
			}
			for(int k=pf,k0=0;k<=pf+rep[j].size()-1;k++,k0++)
			{
				rr[k]=rep[j][k0];
			}
			if(rr==to)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
