#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+5,M=1e6+5,p=37;
int n,q;
int pw[M],pre1[M],pre2[M];
int h1[N],h2[N],l[N];

int get1(int l,int r)
{
	if(l>r)
		return 0;
	return pre1[r]-pre1[l-1]*pw[r-l+1];
}

int get2(int l,int r)
{
	if(l>r)
		return 0;
	return pre2[r]-pre2[l-1]*pw[r-l+1];
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=1e5;i++)
		pw[i]=pw[i-1]*p;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
			h1[i]=h1[i]*p+s1[j]-'a'+1;
		for(int j=0;j<s2.size();j++)
			h2[i]=h2[i]*p+s2[j]-'a'+1;
		l[i]=s1.size();
	}
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++)
			pre1[i+1]=pre1[i]*p+s1[i]-'a'+1;
		for(int i=0;i<s2.size();i++)
			pre2[i+1]=pre2[i]*p+s2[i]-'a'+1;
		s1='0'+s1,s2='0'+s2;
		int len=s1.size()-1,k1=0;
		for(int i=1;i<=len;i++)
		{
			if(s1[i]==s2[i])
				k1++;
			else
				break;
		}
		int ans=0;
		for(int i=0;i<=k1;i++)
			for(int k=1;k<=n;k++)
				if(i+l[k]<=len)
					if(get1(i+1,i+l[k])==h1[k]&&get2(i+1,i+l[k])==h2[k]&&get1(i+l[k]+1,len)==get2(i+l[k]+1,len))
						ans++;
		printf("%d\n",ans);
	}
}
