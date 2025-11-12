#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,a[N],pp[N],fac[N],cnt[N];
char s[N];
bool check1()
{
	for(int i=1;i<=n;i++)
		if(s[i]=='0') return 0;
	return 1;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=11)
	{
		for(int i=1;i<=n;i++) pp[i]=i;
		int sum=0;
		do{
			int ans=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=a[pp[i]]) 
				{
					cnt++;
					continue;
				}
				if(s[i]=='0') cnt++;
				else ans++;
			} 
			if(ans>=m) sum++,sum%=mod;
		}while(next_permutation(pp+1,pp+1+n));
		cout<<sum<<endl;
	}
	if(m==1)
	{
		int ans=1; 
		for(int i=1;i<=n;i++) 
		{
			ans=(1ll*ans*fac[n-a[i]-1-cnt[a[i]]])%mod;
			cnt[a[i]]++;
		}
		cout<<((fac[n]-ans)%mod+mod)%mod;
	}
	if(check1())
	{
		bool flag=0;
		for(int i=1;i<=n;i++)
			if(a[i]==0) flag=1;
		if(!flag) return cout<<fac[n],0;
		 
	}
	return 0;
}

