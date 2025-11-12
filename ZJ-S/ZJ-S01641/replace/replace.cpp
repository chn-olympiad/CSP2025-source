#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
int n,q;
string s[maxn][3];
bool find(string ss,int st,int id)
{
	for(int i=1;i<s[i][1].size();i++)
	{
		if(ss[st+i]!=s[id][1][i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		string s1,s2;
		int ans=0;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+s[i][1].size()<=s1.size();j++)
			{
				if(s1[j]==s[i][1][0])
				{
					if(find(s1,j,i))
					{
						string ss=s1.substr(0,j)+s[i][2]+s1.substr(j+s[i][1].size(),s1.size());
						if(ss==s2)
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


