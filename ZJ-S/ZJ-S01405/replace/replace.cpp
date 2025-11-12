#include<bits/stdc++.h>
using namespace std;
int n,q,cnt;
string s1[200010],s2[200010];
bool vis[200010],v[200010];
void dfs(string s,string st)
{
	if(s==st)
	{
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(s.find(s1[i])!=string::npos&&s1[i]!=s2[i]&&!vis[i])
		{
			bool f=0;
			int pos=s.find(s1[i]);
			for(int j=pos;j<pos+s1[i].size();j++)
				if(v[j])
				{
					f=1;
					break;
				}
			if(f) break;
			for(int j=pos;j<pos+s1[i].size();j++)
				v[j]=1;
			vis[i]=1;
			string q1=s.substr(0,pos),q2=s2[i];
			string q3=s.substr(pos+s1[i].size(),s.size()-pos-s1[i].size());
			dfs(q1+q2+q3,st);
			vis[i]=0;
			for(int j=pos;j<pos+s1[i].size();j++)
				v[j]=0;
		}
	}
	return ;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)
	{
		memset(vis,0,sizeof(0));
		cnt=0;
		string s,ss;
		cin>>s>>ss;
		dfs(s,ss);
		printf("%d\n",cnt);
	}
	return 0;
}
