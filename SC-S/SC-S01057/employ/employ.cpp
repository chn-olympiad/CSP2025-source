#include<iostream>

using namespace std;

typedef long long ll;
const int N=510,mod=998244353;

int n,m;
char s[N];
int c[N];
int fact[N],infact[N],mul[N],sum[N];

bool check_A()
{
	for(int i=1;i<=n;i++)
		if(s[i]!='1')
			return false;
	
	return true;
}

int qmi(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1) res=(ll)res*a%mod;
		k>>=1;
		a=(ll)a*a%mod;
	}
	
	return res;
}

void init()
{
	fact[0]=1,infact[0]=1,mul[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=(ll)fact[i-1]*i%mod;
		mul[i]=(ll)mul[i-1]*fact[i]%mod;
	}
	
	int tmp=qmi(mul[n],mod-2);
	
	for(int i=n;i>=1;i--)
	{
		infact[i]=(ll)tmp*mul[i-1]%mod;
		tmp=(ll)tmp*fact[i]%mod;
	}
}

int A(int a,int b)
{
	return fact[a]*infact[a-b]%mod;
}

void solve_A()
{
	init();
	
	int cnt_0=0;
	for(int i=1;i<=n;i++)
	{
		if(!c[i]) cnt_0++;
		else sum[c[i]]++;
	}
	
	for(int i=n;i>=1;i--) sum[i]+=sum[i+1];
	
	int ans=0;
	for(int i=0;i<=cnt_0;i++)
	{
		int x=sum[i+1];
		if(x>=m)
		{
			x=(ll)fact[cnt_0]*fact[n-cnt_0]%mod;
			ans=((ll)ans+x)%mod;
		}
	}
	
	cout<<ans<<endl;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	
	if(check_A()) solve_A();
	
	return 0;
}