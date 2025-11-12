#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int MOD=998244353;
int n,a[5020],sum,mx;

int max_(int a,int b) { return a>b ? a:b; }

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],mx=max_(mx,a[i]);
	if(n<3) return cout<<0,0;
	else if(n==3)
	{
		if(sum>mx*2) cout<<1;
		else cout<<0;
	}
	else if(mx==1)
	{
		long long z=6,m=n*(n-1)*(n-2),res=(m/z%MOD)*2;
		for(int i=4;i<=n/2;i++) z*=i,(m*=(n-i+1))%=MOD,(res+=m%MOD/z%MOD*2)%=MOD;
		if(n%2) z*=n/2+1,(m*=(n/2))%=MOD,(res+=m%MOD/z%MOD)%=MOD;
		cout<<res;
	}
	else 
	{
		long long ans=0;
		map <long long,int> mp;
		map <long long,long long> mx,sum;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				mp[(1<<i)+(1<<j)]=1,sum[(1<<i)+(1<<j)]=a[i]+a[j],mx[(1<<i)+(1<<j)]=max(a[i],a[j]);
		for(int x=3;x<=n;x++)
			for(auto [key,val]:mp)
			{
				long long s=sum[key],m=mx[key];
				for(int i=1;i<=n;i++)
					if(!(key&&(1<<i))&&!mp[key+(1<<i)]&&(s+a[i])>2*(max_(m,a[i]))) ans=(ans+1)%MOD,mp[key+(1<<i)]=1,sum[key+(1<<i)]=sum[key]+a[i],mx[key+(1<<i)]=max_(mx[key],a[i]);
				mp[key]=0;
			}
		cout<<ans;
	}
	return 0;
}
// I love CCF!!