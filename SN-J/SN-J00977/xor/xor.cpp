#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,k,t,ans,a[5000005],dp[2002][2002];
struct node{
	int l,r;
}b[5000005];
bool cmp(node x,node y){
	return x.r < y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		dp[i][i] = a[i];
		if(dp[i][i] == k){
			node p;
			p.l = i;
			p.r = i;
			b[++t] = p;
		}
	}
	for(int l = 2;l <= n;l++){
		for(int i = 1;i <= n - l + 1;i++){
			int j = i + l - 1;
			dp[i][j] = dp[i][j - 1] ^ a[j];
			if(dp[i][j] == k){
				node p;
				p.l = i;
				p.r = j;
				b[++t] = p;
			}
			//cout << i << "," << j << " | "<< dp[i][j] << "\n";
		}
		//cout << endl;
	}
	//for(int i = 1;i <= t;i++) cout << b[i].l << " " << b[i].r << endl;
	sort(b + 1,b + t + 1,cmp);
	if(t){
		int r = b[1].r;
		ans = 1;
		for(int i = 2;i <= t;i++){
			if(b[i].l > r) ans++,r = b[i].r;
		}
	}
	cout << ans;
	return 0;
}
