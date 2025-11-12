#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200010],b[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i]>>b[i];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<0<<endl;
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int t=x.find(a[i]);
			if(t!=-1)
			{
				string s="";
				for(int j=0;j<a[i].size();j++)
				{
					s=s+x[j+t];
					x[j+t]=b[i][j];
				}
				if(x==y)ans++;
				for(int j=0;j<b[i].size();j++)
				  x[j+t]=s[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
