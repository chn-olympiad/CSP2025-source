#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,t,a[N];
set<int> s;
map<string,string> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		int sz=s1.size();
		if(s.find(sz)==s.end())
		{
			s.insert(sz);
		}
	}
	for(int g=1;g<=k;g++)
	{
		t=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++)
		{
			for(auto ed:s)
			{
				if(i+ed-1<s1.size())
				{
					string ss=s1.substr(i,ed);
					if(mp[ss]!=""&&mp[ss]==s2.substr(i,ed))
					{
						string sss=s1;
						for(int j=i;j<=i+ed-1;j++)
						{
							sss[j]=s2[j];
						}
						if(sss==s2) t++;
					}
				}
			}
		}
		cout<<t<<'\n';
	}
	
}

