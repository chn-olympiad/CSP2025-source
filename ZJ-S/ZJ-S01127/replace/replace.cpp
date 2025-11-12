#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
int g[N][27],d[N];
int n,q,ans;
int cnt=1;
string s[N];
void add(string str1,string str2)
{
	int len1=int(str1.length());
	int p=0;
	for(int i=0;i<len1;i++)
	{
		if(g[p][int(str1[i])-'a']==0)
			g[p][int(str1[i])-'a']=cnt++;
		p=g[p][int(str1[i])-'a'];
	}
	d[p]+=1;
	s[p]=str2;
}
void check(string str1,string str2,string c,int p,int pp)
{
	int len=str1.length(),lenc=c.length();
	bool f=1;
	if(p+lenc-1>len) return;
	for(int i=0;i<len;i++)
	{
		if(i<=lenc+p-1&&i>=p)
		{
			if(c[i-p]!=str2[i])
			{
				f=0;
				break;
			}
		}
		else
		{
			if(str1[i]!=str2[i])
			{
				f=0;
				break;
			}
		}
	}
	if(f==1)
		ans+=d[pp];
		
}
void query(string str1,string str2,int st)
{
	int len=str1.length();
	int p=0;
	for(int i=st;i<len;i++)
	{
		if(g[p][int(str1[i])-'a']==0)
			break;
		p=g[p][int(str1[i])-'a'];
//		cout<<p<<' ';
		if(int(s[p].length())!=0)
			check(str1,str2,s[p],st,p);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string str1,str2;
	string t;
	for(int i=1;i<=n;i++)
	{
		cin>>str1>>str2;
		add(str1,str2);
//		cout<<'\n';
	}
	while(q--)
	{
		ans=0;
		cin>>str1>>str2;
		if(int(str1.length())!=int(str2.length()))
		{
			cout<<0<<'\n';
			continue; 
		}
		int len=str1.length();
		for(int i=0;i<len;i++)
			query(str1,str2,i);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2 
l a
al aa
a b
c d
ll la
la lb

*/
