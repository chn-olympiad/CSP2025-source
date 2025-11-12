//bqq miaomiaomiao
//30 i guess --16:10
//no chance. --18:20
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,vector<string>>mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2,mp[s1].push_back(s2);
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=0;i<t1.size();i++)
		{
			for(int j=1;j<=t1.size()-i;j++)
			{
				string t=t1.substr(i,j);
				if(!mp[t].size())
				{
					continue;
				}
				for(string x:mp[t])
				{
					string s=t1.substr(0,i)+x;
					for(int k=i+j;k<t1.size();k++)
					{
						s+=t1[k];
					}
					ans+=(s==t2);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}