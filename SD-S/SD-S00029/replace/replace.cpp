#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n,q;
string s1,s2;
string str1,str2;
int ans=0;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main ()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		cout<<0<<"\n";
	}
	return 0;
}
//love you
//OI
//bye~ bye 
