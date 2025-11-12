#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,k;
int a[500010];
int ls[500010];
set<int> s;
int __xor(int a,int b)
{
	int t1=a,t2=b;
	bool s1[30],s2[30];
	int p=0;
	while(t1||t2)
	{
		s1[++p]=t1&1;
		s2[p]=t2&1;
		t1=t1>>1;
		t2=t2>>1;
	}
	int res=0;
	for(int i=1;i<=p;i++)
	{
		bool x;
		if(s1[i]==s2[i])
		{
			x=0;
		}
		else
		{
			x=1;
		}
		res+=(x<<(i-1));
	}
	return res;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ss=__xor(ss,a[i]);
		ls[i]=ss;
	}
	s.insert(0);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int tgt=__xor(k,ls[i]);
		if(s.find(tgt)!=s.end())
		{
			cnt++;
			s.clear();
		}
		s.insert(ls[i]);
	}
	cout<<cnt;
	return 0;
}