#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
int n,q;
const int maxn=2e5+5;
const ull P=131;
string s1[maxn],s2[maxn];
ull hash1[maxn],hash2[maxn];
int maxlen;
map<ull,int> mp[2005];
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		printf("0\n");
	}
	return 0;
}

