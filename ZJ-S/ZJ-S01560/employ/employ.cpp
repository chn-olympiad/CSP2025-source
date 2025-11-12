#include<iostream>
#include<algorithm>
using namespace std;
int a[505],id[505],mod = 998244353;
char c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> c[i];
	for(int i = 1;i <= n;i++) cin >> a[i],id[i] = i;
	long long ans = 0;
	do
	{
		long long cnt = 0,fl = 0;
		for(int i = 1;i <= n;i++) 
		{
			if(c[i] == '0' || cnt >= a[id[i]]) cnt++;
			else fl++;
		}
		if(fl >= m) ans = (ans + 1) % mod;
	}while(next_permutation(id + 1,id + n + 1));
	cout << ans << "\n";
	return 0;
}
