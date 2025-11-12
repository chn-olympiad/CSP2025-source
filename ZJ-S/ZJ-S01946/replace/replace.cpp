#include<bits/stdc++.h>
#define Mod 998244353
#define int long long
#define N 5000005
using namespace std;
int ans,le1,le2,n,q,a[N][3],b[N],c[N],bas[N+2];
string s1,s2;
int Hash(string s)
{
	int ans=0,le=s.length();
	for(int i=0;i<le;i++) ans=(ans*29+s[i]-'a')%Mod;
	return ans;
}
int Mo(int x) { return (x%Mod+Mod)%Mod; }
int getb(int x,int y) { return b[y]-b[x-1]*bas[y-x+1]; }
int getc(int x,int y) { return c[y]-c[x-1]*bas[y-x+1]; }
int che(int id)
{
	if(a[id][2]>le1) return 0;
	for(int i=1;i+a[id][2]<=le1+1;i++)
	{
		if(Mo(getb(i,i+a[id][2]-1))==a[id][0] && Mo(getc(i,i+a[id][2]-1))==a[id][1]
		&& Mo(getb(1,i-1))==Mo(getc(1,i-1)) && Mo(getb(i+a[id][2],le1))==Mo(getc(i+a[id][2],le1)))
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q); bas[0]=1;
	for(int i=1;i<N;i++) bas[i]=bas[i-1]*29%Mod;
	for(int i=1;i<=n;i++)
		cin>>s1,a[i][0]=Hash(s1),
		cin>>s2,a[i][1]=Hash(s2),
		a[i][2]=s1.length();
	while(q--)
	{
		cin>>s1>>s2; ans=0;
		le1=s1.length(),le2=s2.length();
		if(le1!=le2) { cout<<"0\n"; continue; }
		b[1]=s1[0]-'a'; for(int i=1;i<le1;i++) b[i+1]=(b[i]*29+s1[i]-'a')%Mod;
		c[1]=s2[0]-'a'; for(int i=1;i<le2;i++) c[i+1]=(c[i]*29+s2[i]-'a')%Mod;
		for(int i=1;i<=n;i++) ans+=che(i);
		printf("%lld\n",ans);
	}
	return 0;
}