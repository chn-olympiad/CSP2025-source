#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,k,a[N],S[N];
int dp[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        S[i]=S[i-1]^a[i];//前缀异或和
    }
	return 0;
}
 
