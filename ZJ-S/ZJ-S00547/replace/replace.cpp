#include<bits/stdc++.h>
using namespace std;
const int slen=2e5+10;
map<string,string>mp;
int ans;
string s;
string dfs(string s)
{
  for(int i=0;i<s.size();i++)
  {
  	for(int j=i;j<s.size();j++)
  	{
  	  string st="";
  	  for(int k=i;k<=j;k++) st=st+s[k];
  	  for(int k=mp.begin();k<mp.end();k++)
  	  {
  	  	string stq=st;
  	  	if(mp.find(st)!=mp.end())
  	  	{
  	  	  stq=mp[st];
  	  	  if()
		}
	  }
	}
  }
}
int main()
{
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
  int n,p;
  cin>>n>>p;
  for(int i=1;i<=n;i++)
  {
  	string a,b;
  	cin>>a>>b;
  	mp[a]=b;
  }
  for(int i=1;i<=p;i++)
  {
  	ans=0;
  	cin>>s;
  	dfs("");
  }
  return 0;
}