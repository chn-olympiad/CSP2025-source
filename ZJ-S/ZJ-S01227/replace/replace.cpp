#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10 ;
int n,q; 
vector<string> t[2];
vector<int> nxt[N];
int st,ed,cnt;
void diff(string a,string b)
{
	for(int i=1;i<a.length();i++)
	{
		if( st == 0 && a[i] != b[i] ) st = i;
		if( a[i] != b[i] ) ed = i ;
	}
	return ;
}
void kmp(string s,int idx)
{
	int j=0;
	nxt[idx].push_back(0);
	nxt[idx].push_back(0);
	for(int i=2,j=0;i<s.length();i++)
	{
		while( j && s[i] != s[j+1] ) j=nxt[idx][j];
		if( s[i] == s[j+1] ) j++;
		nxt[idx].push_back(j);
	}
	nxt[idx].push_back(0);
}
int kmpp(string a,string b,int idx)
{
	int res = 0 ;
	int j=1,l=1;
	string t1=t[0][idx-1],t2=t[1][idx-1];
	for(int i=1,j=0;i<a.length();i++)
	{
		while( j && a[i] != t1[j+1] ) j=nxt[idx*2-1][j];
		if( a[i]==t1[j+1] ) j++;
		if( j+1 == t1.length() )
		{
			for(int k=1,l=0;k<b.length();k++)
			{
				while( l && b[k] != t2[l+1] ) l=nxt[idx*2][l];
				if( b[k]==t2[l+1] ) l++;
				if( l+1 == t2.length() && l == j && k >= ed && k-t2.length()+2<=st ) res++;
				if( l+1 == t2.length() ) l=nxt[idx*2][l];
			}
			j=nxt[idx*2-1][j];
		}
	}
	return res;
}
int main()
{
	freopen("replace.in","in",stdin);
	freopen("replace.out","out",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		t[0].push_back(s1);
		t[1].push_back(s2);
		kmp(s1,i*2-1);
		kmp(s2,i*2);
	}
	for(int i=1;i<=q;i++)
	{
		st = ed = 0 ;
		string s1,s2;
		cin>>s1>>s2;
		s1=" "+s1;
		s2=" "+s2;
		diff(s1,s2);
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			cnt+=kmpp(s1,s2,j);
		}
		cout<<cnt<<'\n';
	}
	return 0;
}