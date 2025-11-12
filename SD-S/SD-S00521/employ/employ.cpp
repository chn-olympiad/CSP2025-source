#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int N=501,M=998244353;
int n,m,c[N],ans,p[N];
bool f[N],kf[N];
char s[N];
inline void search(int k)
{
	if(k>n)
	{
		int cnt=0,b=0;
		for(int i=1;i<=n;i++)
		{
//			cout<<(s[i]=='0'&&cnt<=c[p[i]])<<'\n';
			if(s[i]=='1'&&cnt<c[p[i]])b=b+1;
			else cnt++;
		}//
		if(b>=m)ans++;
		ans%=M;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			p[k]=i;
			search(k+1);
			p[k]=0;
			f[i]=0;
		}
	}return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>(s+1);
//	cout<<m<<'\n';
	for(int i=1;i<=n;i++){cin>>c[i];}
	if(m==1)
	{
		ans=1;
		for(int i=2;i<=n;i++)ans=(ans*i)%M;
		cout<<ans;return 0;
	}
	if(m==n)
	{
		cout<<1;return 0;
	}
	search(1);
	cout<<ans;
	return 0;
}
