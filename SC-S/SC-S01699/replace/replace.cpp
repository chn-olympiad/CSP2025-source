#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int X=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=X*10+(ch-'0'); ch=getchar();}
	return X*f;
}
const int mod1=1432413469,mod2=747218181;
int n,m;
string s1[200005],s2[200005];
string t1,t2;
int pi[2000005],ok[2][2000005];
void kmp(int op,string s,string t)
{
	for(int i=0;i<t.size();i++) ok[op][i]=0;
	if(s.size()>t.size()) return ;
	for(int i=2,j=0;i<s.size();i++)
	{
		while(j&&s[j+1]!=s[i]) j=pi[j];
		if(s[j+1]==s[i]) j++;
		pi[i]=j;
	}
	for(int i=1,j=0;i<t.size();i++)
	{
		while(j&&s[j+1]!=t[i]) j=pi[j];
		if(s[j+1]==t[i]) j++;
		if(j==s.size()-1)
		{
			ok[op][i]=1;
			j=pi[j];
		}
	}
}

void work()
{
	n=read(),m=read();
	int ml=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		s1[i]=' '+s1[i];
		s2[i]=' '+s2[i];
		ml=max(ml,(int)s1[i].size());
	}
	if(1||(n<=2000&&m<=2000&&ml<=2000))
	{
		while(m--)
		{
			cin>>t1>>t2;
			int as=0;
			if(t1.size()!=t2.size())
			{
				printf("0\n");
				continue;
			}
			t1=' '+t1;
			t2=' '+t2;
			int d1=0,d2=0;
			for(int i=1;i<t1.size();i++)
			{
				if(t1[i]!=t2[i]) d2=i;
			}
			for(int i=t1.size()-1;i;i--)
			{
				if(t1[i]!=t2[i]) d1=i;
			}
			//cout<<t1<<' '<<t2<<'\n';
			for(int i=1;i<=n;i++)
			{
				kmp(0,s1[i],t1);
				kmp(1,s2[i],t2);
				for(int j=max(1,d2);j<t1.size();j++)
				{
					if(ok[0][j]&&ok[1][j])
					{
						//cout<<i<<' '<<j-s1[i].size()+2<<' '<<j<<' '<<d1<<' '<<d2<<'\n';
						if(!d1||(j-s1[i].size()+2<=d1)) as++;
					}
				}
			}
			printf("%d\n",as);
		}	
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int tt=1;
	while(tt--) work();
	return 0;
} 