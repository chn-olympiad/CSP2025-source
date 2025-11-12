//我也不知道为什么就想出来了这么一个奇怪的做法。
//正确性可以保证，但复杂度是什么，我不知道。
#include <bits/stdc++.h>
using namespace std;
const char EMP='a'-1;
const int N=5e6+100;
int n,q,ct,s[N][29],d[N],fa[N],app[N],fl[N];
char str[N];
map<string,map<string,int> >mp;
void dfs(int x)
{
	if(d[x]==0)
	{
		fl[x]=x;
	}
	else if(d[x]==1)
	{
		fl[x]=fa[x];
	}
	else
	{
		fl[x]=fl[fa[x]];
		while(d[fl[x]]&&!s[fl[x]][str[x]-EMP])
		{
			fl[x]=fl[fl[x]];
		}
		if(s[fl[x]][str[x]-EMP])
		{
			fl[x]=s[fl[x]][str[x]-EMP];
		}
	}
	app[x]+=app[fl[x]];
	for(int i=0;i<29;i++)
	{
		if(s[x][i])
		{
			dfs(s[x][i]);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string ss,t;
		cin>>ss>>t;
		if(ss!=t)
		{
			int l=0,r=ss.size()-1;
			while(ss[l]==t[l])
			{
				l++;
			}
			while(ss[r]==t[r])
			{
				r--;
			}
			string u=ss.substr(l,r-l+1),v=t.substr(l,r-l+1);
			//if(u=="aaaab"&&v=="baaaa")
			//{
				//cout<<"!!! "<<l<<" "<<r<<" "<<ss.size()<<"\n";
			//}
			if(!mp[u][v])
			{
				ct++;
				mp[u][v]=ct;
			}
			string w=ss.substr(0,l)+EMP+ss.substr(r+1);
			//cout<<i<<" "<<u<<" "<<v<<" "<<w<<"\n";
			int ix=mp[u][v];
			for(int j=0;j<w.size();j++)
			{
				if(!s[ix][w[j]-EMP])
				{
					ct++;
					s[ix][w[j]-EMP]=ct;
					fa[ct]=ix;
					d[ct]=d[ix]+1;
					str[ct]=w[j];
				}
				ix=s[ix][w[j]-EMP];
			}
			app[ix]++;
		}
	}
	for(map<string,map<string,int> >::iterator it=mp.begin();it!=mp.end();it++)
	{
		for(map<string,int>::iterator jt=(it->second).begin();jt!=(it->second).end();jt++)
		{
			dfs(jt->second);
		}
	}
	//while(q--)
	for(int tt=1;tt<=q;tt++)
	{
		string ss,t;
		cin>>ss>>t;
		if(ss.size()!=t.size())
		{
			printf("0\n");
			continue;
		}
		/*
		if(tt==76)
		{
			cout<<ss<<" "<<t<<" "<<ss.size()<<"\n";
			for(int j=0;j<ss.size();j++)
			{
				if(ss[j]=='b')
				{
					cout<<"ss["<<j<<"] ";
				}
				if(t[j]=='b')
				{
					cout<<"t["<<j<<"] ";
				}
			}
			cout<<"\n";
		}
		*/
		int l=0,r=ss.size()-1;
		while(ss[l]==t[l])
		{
			l++;
		}
		while(ss[r]==t[r])
		{
			r--;
		}
		string u=ss.substr(l,r-l+1),v=t.substr(l,r-l+1);
		if(mp.find(u)!=mp.end()&&mp[u].find(v)!=mp[u].end())
		{
			string w=ss.substr(0,l)+EMP+ss.substr(r+1);
			//cout<<tt<<" "<<u<<" "<<v<<" "<<w<<"\n";
			int ix=mp[u][v];
			int as=app[ix];
			for(int j=0;j<w.size();j++)
			{
				while(d[ix]&&!s[ix][w[j]-EMP])
				{
					ix=fl[ix];
				}
				if(s[ix][w[j]-EMP])
				{
					ix=s[ix][w[j]-EMP];
				}
				as+=app[ix];
			}
			printf("%d\n",as);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}