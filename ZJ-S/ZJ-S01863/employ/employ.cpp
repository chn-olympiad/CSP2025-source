#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,m,cnt0;
long long ans;
int a[505],b[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i],cnt0+=(a[i]==0);
	if(n<=10)
	{
		for(int i=1;i<=n;i++) b[i]=i;
		do
		{
			int cnt=0,now=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=a[b[i]]) cnt++;
				else if(s[i-1]=='1') now++;
				else cnt++;
			}
			if(now>=m) ans++;
		}
		while(next_permutation(b+1,b+1+n));
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		if(cnt0)
		{
			cout<<0;
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
}
