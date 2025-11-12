#include <bits/stdc++.h>
using namespace std;
int n,q,l,L,st1,st2[200005],ed1,ed2,ans;
string s1[200005],s2[200005],t1,t2,tt1,tt2;
void find(int j,string s1,string s2)
{
	st2[j]=-1;ed2=-1;
	for(int i=0;i<L;i++)
	{
		if(s1[i]!=s2[i])
		{
			if(st2[j]!=-1)ed2=i;
			else st2[j]=i;
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		L=s1[i].length();
		find(i,s1[i],s2[i]);
	}
	while(q--)
	{
		cin>>t1>>t2;st1=-1;ed1=-1;
		l=t1.length();ans=0;
		for(int i=0;i<l;i++)
		{
			if(t1[i]!=t2[i])
			{
				if(st1!=-1)ed1=i;
				else st1=i;
			}
		}
		tt1=t1.substr(st1,ed1-st1+1);
		tt2=t2.substr(st1,ed1-st1+1);
		for(int i=1;i<=n;i++)
		{
			L=s1[i].length();
			if(st1<st2[i]||st1-st2[i]+L>l||st1-st2[i]+L<=ed1)continue;
			if(s1[i]==t1.substr(st1-st2[i],L)&&s2[i]==t2.substr(st1-st2[i],L))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
