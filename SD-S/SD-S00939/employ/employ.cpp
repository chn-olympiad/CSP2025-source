#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[505],p[15],f[505][505],ss[505],r[505];
long long ans=0,fl,ee,ff;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i],fl=fl|(c[i]==0),ss[c[i]]++,ee|=(c[i]);
	r[0]=ss[0];
	for(int i=0;i<s.length();i++)
			if(s[i]=='1')
			{
				ff=1;
				break;
			}
	for(int i=1;i<=n;i++)
		r[i]=r[i-1]+ss[i];
	long long res=1; 
	for(int i=1;i<=n;i++)
		res=res*i%mod;
	for(int i=0;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=f[i-1][j-1]+f[i-1][j],f[i][j]%=mod;
	if(!ee||!ff)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		for(int i=0;i<s.length();i++)
			if(s[i]=='0')
			{
				fl=1;
				break;
			}
		if(fl)
			cout<<0;
		else
		{
			cout<<res;
		}
		return 0;
	}
		for(int i=1;i<=n;i++)
			p[i]=i;
		do
		{
			int cnt=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=c[p[i]]||!(s[i-1]-'0'))
					cnt++;
				else
					sum++;
			}
			if(sum>=m)
				ans++,ans%=mod; 
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	return 0;
}

