#include<iostream>
#include<algorithm>
using namespace std;
long long n,a[5005],f[2][5005],mod = 998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	long long ans = 0,m = a[n] + 1;
	f[0][0] = 1;
	for(int I = 0;I <= n;I++)
	{
		int i = I % 2,i1 = (I + 1) % 2;
		if(I >= 3)
		{
			for(int j = a[I] + 1;j <= m;j++) ans = (ans + f[i1][j]) % mod; 
		}
		for(int j = 0;j <= m;j++) f[i1][j] = f[i][j];
		for(int j = 0;j <= m;j++)
		{
			f[i1][min(m,j + a[I + 1])] = (f[i1][min(m,j + a[I + 1])] + f[i][j]) % mod;
		}
	}
	cout << ans << "\n"; 
	return 0; 
} 
