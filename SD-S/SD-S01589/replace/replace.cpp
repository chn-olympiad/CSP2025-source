#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ui N=2e5+5,INF=0x3f3f3f3f;
ui n,m,sa[N],ea[N];
string a[N],b[N],a2[N],b2[N];

void solve()
{
	cin>>n>>m;
	for(ui i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ui s=a[i].size(),e=a[i].size();
		for(ui j=0;j<a[i].size();j++)
		{
			if(a[i][j]!=b[i][j])
			{
				if(s==a[i].size())
					s=j;
				e=j;
			}
		}
		sa[i]=s,ea[i]=e;
	}
	for(ui i=1;i<=m;i++)
	{
		cin>>a2[i]>>b2[i];
		if(a2[i].size()!=b2[i].size())
			cout<<0<<'\n';
		else
		{
			ui s=a2[i].size(),e=a2[i].size(),ans=0;
			for(ui j=0;j<a2[i].size();j++)
			{
				if(a2[i][j]!=b2[i][j])
				{
					if(s==a2[i].size())
						s=j;
					e=j;
				}
			}
			for(ui j=1;j<=n;j++)
			{
				if(sa[j]>s||a2[i].size()-e<a[j].size()-ea[j]||(e-s!=ea[j]-sa[j]))
					continue;
				bool flag=true;
				for(ui k=s-sa[j],k2=0;k2<a[j].size();k++,k2++)
				{
					if(a[j][k2]!=a2[i][k]||b[j][k2]!=b2[i][k])
					{
						flag=false;
						break;
					}
				}
				if(flag)
					ans++;
			}
			cout<<ans<<'\n';
		}
	}
	
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

