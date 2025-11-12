#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int N=200005;

int n,m;

map<int,int> tot;

string s1[N],s2[N],t1,t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int q=1;q<=m;q++)
	{
		cin>>t1>>t2;
		int len=t1.size();
		map<string,int> mp;
		for(int i=1;i<=n;i++)
		{
			int l=s1[i].size();
			string ss="",sr="";
			for(int j=l-1;j<len;j++)
			{
				if(j-l+1>0) ss+=t1[j-l],sr+=t2[j-l];
				if(ss!=sr) break;
				string s=t1.substr(j-l+1,l);
				if(s==s1[i])
				{
					string str=t1.substr(0,j-l+1)+s2[i]+t1.substr(j+1,len-j-1);
					mp[str]++;
				}
			}
		}
		int res=mp[t2];
		printf("%d\n",res);
	}
	return 0;
}
