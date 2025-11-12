#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
string s1[M],s2[M];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(m--)
	{
		int ans=0;
		string st1,st2;
		cin>>st1>>st2;
		string ss1=st1,ss2=st2;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<n-s1[i].size()+2;j++)
			{
				string str;
				for(int x=j;x<j+s1[i].size();x++)str+=ss1[x];
				if(str==s1[i])
				{
					int sssss=-1;
					string sss="";
					for(int x=0;x<j;x++)sss+=ss1[x];
					for(int x=j;x<j+s2[i].size();x++)sss+=s2[i][++sssss];
					for(int x=j+s2[i].size();x<ss1.size()-(s1[i].size()-s2[i].size());x++)sss+=ss1[x];
					if(sss==ss2)ans++;
					ss1=st1,ss2=st2;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
