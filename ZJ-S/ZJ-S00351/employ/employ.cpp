#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fre {freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);}
#define pii pair<LL,LL>
LL n,m,a[550],cnt,ans=1,p=998244353;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	fre;
	cin>>n>>m>>s;
	for(LL i=1;i<=n;++i) cin>>a[i];
	for(LL i=0;i<n;++i) cnt+=(s[i]-'0');
	if(cnt==n||(m==1&&s[0]=='1'))
	{
		for(LL i=1;i<=n;i++) ans=(ans*i)%p;
		cout<<ans<<endl;
	}
	if(cnt<m)
	{
		cout<<0<<endl;
		return 0;
	}
}
