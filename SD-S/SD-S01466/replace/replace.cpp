#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5,M=5e6+5;
vector<char>p1[N];
vector<char>p2[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string s1;
		cin>>s1;
		for(int j=0;j<s1.size();j++)p1[i].push_back(s1[j]);
		s1.clear();
		cin>>s1;
		for(int j=0;j<s1.size();j++)p2[i].push_back(s1[j]);
		s1.clear();
//		cout<<p1[i].size();
	}
	while(m--)
	{
		string s1,s2;
		cin>>s1;
		cin>>s2;
//		cout<<s1.size()<<endl;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(s1.size()<p1[i].size())continue;
			for(int j=0;j<s1.size();j++)
			{
//				cout<<"pp"<<" ";
				int flag=1;
				for(int k=0;k<p1[i].size();k++)
				{
					if(s1[j+k]!=p1[i][k])
					{
						flag=0;
					}
				}
				if(flag==1)
				{
					for(int k=0;k<p2[i].size();k++)
					{
						if(s2[j+k]!=p2[i][k])
						{
							flag=0;
						}
					}
					for(int k=0;k<j;k++)
					{
						if(s1[k]!=s2[k])flag=0;
					}
					for(int k=j+k+1;k<s1.size();k++)
					{
						if(s1[k]!=s2[k])flag=0;
					}
				}
				ans+=flag;
			}
		}
		cout<<ans<<endl;
		s1.clear(),s2.clear();
	}
	return 0;
 } 
