#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct A{
	string s1,s2;
}s[10010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--)
	{
		ll ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=0;j<t1.size();j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(j-i+1==s[k].s1.size())
					{
						bool flag=true;
						for(int l=0;l<j-i+1;l++)
						{
							if(s[k].s1[l]!=t1[i+l]) flag=false;
						}
						if(flag)
						{
							bool f=true;
							for(int l=0;l<t1.size();l++)
							{
								char x=t1[l],y=t2[l];
								if(l>=i && l<=j) x=s[k].s2[l-i];
								if(x!=y) f=false;
							}
							if (f)
							{
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}