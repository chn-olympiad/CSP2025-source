#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,o[5000005],fo[5000005];
int h[5000005][2],l[5000005];
int pr[2][5000005];
const int p=1e9+7;
string s,t;
int fst(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,len,u,v,res;
	cin>>n>>q;
	o[0]=1;
	for(i=1;i<=5e6;i++)o[i]=o[i-1]*56%p;
	fo[5000000]=fst(o[5000000],p-2);
	for(i=5e6-1;i>=0;i--)fo[i]=fo[i+1]*56%p;
	for(i=1;i<=n;i++)
	{
		cin>>s>>t;
		l[i]=s.length();
		for(j=0;j<l[i];j++)
		{
			h[i][0]=(h[i][0]+(s[j]-'a'+1)*o[j]%p)%p;
			h[i][1]=(h[i][1]+(t[j]-'a'+1)*o[j]%p)%p;
		}
	}
	while(q--)
	{
		cin>>s>>t;
		len=s.length();
		for(i=1;i<=len;i++)
		{
			pr[0][i]=(pr[0][i-1]+(s[i-1]-'a'+1)*o[i-1]%p);
			pr[1][i]=(pr[1][i-1]+(t[i-1]-'a'+1)*o[i-1]%p);
		}
		res=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=len-l[i]+1;j++)
			{
				u=(pr[0][j+l[i]-1]-pr[0][j-1]+p)%p*fo[j-1]%p;
				v=(pr[1][j+l[i]-1]-pr[1][j-1]+p)%p*fo[j-1]%p;
				if(u!=h[i][0]||v!=h[i][1])continue;
				u=(pr[0][len]-u*o[j-1]%p+v*o[j-1]%p);
				if(u!=pr[1][len])continue;
				res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb


*/