#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int sum[N],a[N];
int n,k;
const int M = (1 << 20) + 10;
int pre[M];
int vis;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i] = (sum[i-1] ^ a[i]);
	}
	memset(pre,-1,sizeof pre);
	pre[0] = 0;
	int ans = 0;
	for(int i=1;i<=n;i++){
		int x = (sum[i] ^ k);
		if(pre[x] >= vis){
			pre[x] = -1;
			ans ++ ;
			vis = i;
		}
		pre[sum[i]] = i;
	}
	cout << ans;
	return 0;
}
//CSP-S RP++;