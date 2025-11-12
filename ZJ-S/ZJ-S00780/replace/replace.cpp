#include<bits/stdc++.h>
#define rint register int
using namespace std;
const int N=100005;
int n,q;
string s1[N],s2[N],t1,t2;
void read(rint &s)
{
	s=0;char c=getchar();int f=1;
	for(;c<48||c>57;c=getchar()) (c=='-')&&(f=-1);
	for(;c>47&&c<58;c=getchar()) s=(s<<1)+(s<<3)+(c^48);
	s*=f;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	for(rint i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(;q;q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			puts("0");
			continue;
		}
		int ans=0;
		for(rint i=1;i<=n;i++)
		{
			string s_1=t1,s_2=t2;
			int x=s_1.find(s1[i]);
			if(x==-1) continue;
			if(s1[i]==s2[i]&&t1==t2)
			{
				while(s_1.size())
				{
					if(x==-1) break;
					s_1.erase(x,s1[i].size());
					x=s_1.find(s1[i]);
					ans++;
				}
				continue;
			}
			string s=s_1;
			for(rint j=x;j<x+s1[i].size();j++) s[j]=s2[i][j-x];
			if(s==s_2) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
