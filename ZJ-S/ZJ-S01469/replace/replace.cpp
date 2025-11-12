#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string> >v[500005];
int n,q,t[500005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s,s1;
		cin>>s>>s1;
		v[s.size()].push_back({s,s1});
		t[s.size()]=1;
	}
	while(q--)
	{
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=t1.size();i++)
		{
			if(!t[i]) continue;
			for(int j=0;j+i-1<t1.size();j++)
			{
				if(j!=0&&t1[j-1]!=t2[j-1]) break;
				string s=t1.substr(j,i),s1=t2.substr(j,i);
				int b=0,c=0;
				for(pair<string,string> k:v[i])
				{
					if(k.first==s&&k.second==s1) b++;
				}
				if(b==0) continue;
				for(int k=j+i;k<t1.size();k++)
				{
					if(t1[k]!=t2[k])
					{
						c=1;
						break;
					}
				}
				if(c==0) ans+=b;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
