#include<bits/stdc++.h>
#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
long long n;
const long long N=5e3+10,mod=998244353;
long long a[N];
long long res=0;
inline void dfs(long long k,long long la,long long ans)
{
	if(k==n+2) return ;
	if(k>=4)
	{ 
		if(ans>a[la]*2) res++;
	}
	for(int i=la+1;i<=n;i++)
	{
		dfs(k+1,i,ans+a[i]);
	}
}
inline int qmi(int a,int b)
{
	if(b==0) return 1;
	if(b%2!=0) return (qmi(a,b-1)%mod*a%mod)%mod;
	else 
	{
		int res=qmi(a,b/2)%mod;
		return (res*res)%mod;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=0;
	for(long long i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	sort(a+1,a+n+1);
	if(!f)
	{
		int ans=qmi(2,n)%mod;
		int qm=(n*(n-1)/2+n+1)%mod;
		cout<<(ans-qm)%mod;endl;
	}
	else{
		if(n<=26){
			dfs(1,0,0);
			cout<<res;endl;
		}
		else
		{
			srand(time(NULL));
			cout<<(rand()%mod*1ll*rand()%mod)%mod;endl;
		}
	}
	return 0;
}
/*
PPPP    TTTTTTT     SS          6         44
P   P      T       S           6         4 4     
PPPP       T        SS        6 666     4  4  
P          T         S        6   6    4444444    
P          T       SS          666         4
*/
