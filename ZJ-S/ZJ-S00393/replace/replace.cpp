#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,cnt,st,en;
string str1,str2,s1,s2,ss1,ss2;
map <string,vector<string> > m;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>str1>>str2;
		cnt=0;
		m[str1].push_back(str2);
	}
	while(q--)
	{
		cin>>str1>>str2;
		cnt=0;
		if(str1.size()!=str2.size()) {cout<<0;continue;}
		for(int i=0;i<str1.size();i++)
			if(str1[i]!=str2[i]) {st=i;break;}
		for(int i=str1.size()-1;i>=0;i--)
			if(str1[i]!=str2[i]) {en=i;break;}
		for(int i=st;i<en;i++) s1=s1+str1[i],s2=s2+str2[i];
		for(int l=st;l>=0;l--)
		{
			ss1=s1,ss2=s2;
			for(int r=en;r<str1.size();r++)
			{
				s1=s1+str1[r],s2=s2+str2[r];
				int len=m[s1].size();
				for(int i=0;i<len;i++)
					if(m[s1][i]==s2)
						cnt++;
			}
			if(l==0) break;
			ss1=str1[l-1]+ss1,ss2=str2[l-1]+ss2;
			s1=ss1,s2=ss2;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
