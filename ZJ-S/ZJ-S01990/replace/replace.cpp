#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200007],b[200007],l1,l2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(q--)
	{
		int ans=0;
		cin>>l1>>l2;
		if(l1.size()!=l2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int f=0;
		for(int j=1;j<=n;j++)
		{
			f=1;
			for(int i=0;i<l1.size();i++)
			{
				if(l1[i]!=l2[i])
				{
					if(f==1)
					{
						f=2;
						break;
					}
					for(int k=0;k<a[j].size();k++)
					{
						if(l1[k+i]!=a[j][k]||l2[k+i]!=b[j][k])
						{
							f=2;
							break;
						}
					}
					i+=a[j].size()-1;
				}
				if(f==2) break;
			}
			if(f==1) ans++;
		}
		if(f==2) cout<<0<<'\n';
		else cout<<ans<<'\n';
	}
	return 0;
}
