#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e6+10;

int a[N],dp[N],mx[N],n,k;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) a[i]=(a[i-1]^a[i]);
	memset(mx,-0x3f,sizeof(mx));
	mx[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1],mx[a[i]^k]+1);
		mx[a[i]]=max(mx[a[i]],dp[i]);
	}
	cout << dp[n] << '\n';
	return 0;
}
