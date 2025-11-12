#include<bits/stdc++.h>
using namespace std;
string a,b;
map<int,string> s1,s2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,n,q,ans=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>a>>b;
		for(int i=0;i<a.size();i++)
		{
			for(int j=0;j<a.size();j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(s1[k].size()==j-i+1)
					{
						int c,s=0;
						for(c=i;c<=j;c++)
						{
							if(a[c]!=s1[k][s]||b[c]!=s2[k][s])break;
							s++;
						}
						int d;
						for(d=j+1;d<a.size();d++)
						{
							if(a[d]!=b[d])break;
						}
						int e;
						for(e=0;e<i;e++)
						{
							if(a[e]!=b[e])break;
						}
						if(c>j&&d==a.size()&&e==i)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}



