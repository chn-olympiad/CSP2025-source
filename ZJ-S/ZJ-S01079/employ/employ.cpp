#include <bits/stdc++.h>
#define int long long
typedef long long ll;
const ll Mod=998244353;
const int N=505;
using namespace std;
char s[N];
int id[N],c[N];
int fac[N],inv[N];
int ksm(int a,int b){int ans=1;for(;b;b>>=1,a=a*a%Mod)if(b&1)ans=ans*a%Mod;return ans;}
int C(int n,int m){return n<m?0:fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
void add(int &x,int y){x+=y;if(y>=Mod)y-=Mod;}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	fac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%Mod;
	inv[N-1]=ksm(fac[N-1],Mod-2);
	for(int i=N-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%Mod;
	
	//init
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)
	{
		for(int i=1;i<=n;i++)id[i]=i;
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)
			if(s[i]=='0'||cnt>=c[id[i]])cnt++;
	//		for(int i=1;i<=n;i++)cerr<<id[i]<<" \n"[i==n];
	//		cerr<<cnt<<'\n';
			if(n-cnt>=m)ans++;
		}while(next_permutation(id+1,id+n+1));
		cout<<ans<<'\n';
		return 0;
	}
	if(n<=18)
	{
		int nn=1<<n;
		vector<vector<int>>f(n+2,vector<int>(nn,0));
		f[0][0]=1;
		for(int S=0;S<nn;S++)
		{
			int count=0;
			for(int i=0;i<n;i++)
			if(S>>i&1)count++;
			for(int b=1;b<=n;b++)
			if(!(S>>(b-1)&1))
			{
				for(int j=0;j<=n;j++)
				if(s[count+1]=='0')
				add(f[j+1][S|(1<<(b-1))],f[j][S]);
				else{
						if(j>=c[b])add(f[j+1][S|(1<<(b-1))],f[j][S]);
						else add(f[j][S|(1<<(b-1))],f[j][S]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)add(ans,f[i][nn-1]);
		cout<<ans<<'\n';
		return 0;
	}
	if(m==n)
	{
		int ffflag=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')ffflag=1;
		for(int i=1;i<=n;i++)if(c[i]==0)ffflag=1;
		if(ffflag==1)cout<<0<<'\n';
		else cout<<fac[n]<<'\n';
		return 0;
	}
	if(m==1)
	{
		ll ans=fac[n],res=1,Cnt=0;
		vector<int>cnt(n+1);
		for(int i=1;i<=n;i++)cnt[c[i]]+=1;
		for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=n;i++)
		if(s[i]=='1')
		{
			res=res*(cnt[i-1]-Cnt<0?0:cnt[i-1]-Cnt)%Mod;
			Cnt++;
		}
		res=res*fac[n-Cnt]%Mod;
		cout<<(ans-res+Mod)%Mod<<'\n';
		return 0;
	}
	
	int fflag=1;
	for(int i=1;i<=n;i++)if(s[i]=='0')fflag=0;
	if(fflag==1)
	{
		vector<vector<int>>f(n+1,vector<int>(n+1));
		f[0][0]=1;
		vector<int>cnt(n+1);
		for(int i=1;i<=n;i++)cnt[c[i]]+=1;
		for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
		//f[i][j]表示到第i个人，一共有j个人没通过
		for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(j!=0)
			f[i][j]=(f[i][j]+f[i-1][j-1]*max(0ll,cnt[j-1]-(j-1))%Mod)%Mod;
			f[i][j]=(f[i][j]+f[i-1][j]*max(0ll,cnt[n]-cnt[j]-((i-1)-(j-1)))%Mod)%Mod;
		}
		ll ans=fac[n];
		for(int j=n-m+1;j<=n;j++)ans=(ans-f[n][j]+Mod)%Mod;
		cout<<ans<<'\n';
	}
}
