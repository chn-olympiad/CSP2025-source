#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+10,V=5e6+10;
int T,n,cnt,num,e[V][26],rt[N],ct[V],fail[V],tt[N];
string s1,s2,s,u[N];
pair<int,int>val[N];
queue<int>q;
map<pair<int,int>,int>mp;
void ins(int pos,int x)
{
	if(x==s.size())
	{
		++ct[pos];
		return;
	}
	if(!e[pos][s[x]-'a']) e[pos][s[x]-'a']=++cnt;
	ins(e[pos][s[x]-'a'],x+1);
}
void getfail(int rt)
{
	q.push(rt);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<26;i++) if(!e[x][i]) e[x][i]=rt;
		if(!fail[x]) fail[x]=rt;
		for(int i=0;i<26;i++)
		{
			int v=e[x][i];
			if(v==rt)
			{
				e[x][i]=e[fail[x]][i];
			}
			else
			{
				fail[v]=e[fail[x]][i];
				ct[v]+=ct[fail[v]];
				q.push(v);
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;s="";
		int j=0,k=s1.size()-1;
		for(;j<s1.size();j++) if(s1[j]!=s2[j]) break;
		for(;~k;k--) if(s1[k]!=s2[k]) break;
		int val1=0,val2=0;
		for(int p=j;p<=k;p++) val1=(val1*31ll+s1[p]-'a'+1)%998244853,val2=(val2*31ll+s2[p]-'a'+1)%998244853;
		if(!mp.count({val1,val2})) mp[{val1,val2}]=++num,rt[mp[{val1,val2}]]=++cnt;
		for(int p=0;p<j;p++) s+=s1[p];
		if(j<=k) for(int p=k+1;p<s1.size();p++) s+=s1[p];
		u[i]=s;val[i]={val1,val2};tt[i]=j;
		ins(rt[mp[{val1,val2}]],0);
	}
	for(int i=1;i<=num;i++) getfail(rt[i]);
	while(T--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		s="";
		int j=0,k=s1.size()-1;
		for(;j<s1.size();j++) if(s1[j]!=s2[j]) break;
		for(;~k;k--) if(s1[k]!=s2[k]) break;
		int val1=0,val2=0;
		for(int p=j;p<=k;p++) val1=(val1*31ll+s1[p]-'a'+1)%998244853,val2=(val2*31ll+s2[p]-'a'+1)%998244853;
		if(!mp.count({val1,val2}))
		{
			cout<<"0\n";
			continue;
		}
//		int pos=rt[mp[{val1,val2}]];
		long long ans=0;
		for(int p=0;p<j;p++) s+=s1[p];
		if(j<=k) for(int p=k+1;p<s1.size();p++) s+=s1[p];
//		for(int i=0;i<s.size();i++)
//		{
//			if(i>=j-1) ans+=ct[pos];
//			pos=e[pos][s[i]-'a'];
//		}
//		cout<<ans+ct[pos]<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(val[i]==(pair<int,int>){val1,val2})
			{
				int fl=1;
				for(int w=j,p=tt[i];p<u[i].size();p++,w++)
				{
					if(s[w]!=u[i][p])
					{
						fl=0;
						break;
					}
				}
				if(fl)
				{
					for(int w=j-1,p=tt[i]-1;~p;p--,w--)
					{
						if(s[w]!=u[i][p])
						{
							fl=0;
							break;
						}
					}
				}
				ans+=fl;
			}
		}
		cout<<ans<<"\n";
	}
}