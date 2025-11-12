#include<bits/stdc++.h>
using namespace std;
long long n,q,ans;
string s1[200010],s2[200010],t1,t2,y,x,z,t,yy;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0";
			continue;
		}
		for(int l=0;l<t1.size();l++)
		{
			for(int r=l;r<t1.size();r++)
			{
				x=t1.substr(0,l);
				y=t1.substr(l,r-l+1);
				z=t1.substr(r+1,int(t1.size())-r-1);
				for(int k=1;k<=n;k++)
				{
					if(s1[k]==y)
					{
						yy=s2[k];
						t=x+yy+z;
						if(t==t2)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
