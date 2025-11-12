#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005,mod = 998244353;
int n;
int a[N];
int ans = 0;
int f[N][N];//第i件物品j个空间

int Cs(int j,int i)
{
	int tt = 1;
	for(int tk = i + 1;tk <= j;tk++)
		tt = (tt * tk);
	
	for(int tk = 1;tk <= j - i;tk++)
		tt = (tt / tk);
	
	return tt;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int wi = 3;wi <= n;wi++) //a[i]为背包容量
	{
		int summ = 0;
		memset(f,0,sizeof f);
		for(int i = 1;i <= wi - 1;i++) // wi-1 件物品
		{
			for(int j = a[wi];j >= 0;j--) 
			{
				if(j - a[i] >= 0) f[i][j] =(f[i][j] + (f[i-1][j-a[i]] + 1))%mod;
				f[i][j] = (f[i][j] + f[i-1][j])%mod;
			}
			summ =  (summ + Cs(wi-1, i))%mod;
		}
		int buxing = ((f[wi-1][a[wi]] - wi+mod)%mod + 1)%mod ;// buxing
		ans = (ans + ((summ - wi + mod)%mod+ 1) - buxing + mod)%mod ;
	}
	cout<<ans%mod<<"\n";
	
	return 0;
}
