#include <bits/stdc++.h>
using namespace std;
struct node{
	long long d1,d2,d3;
}a[100005];
long long dp[210][210][210];
long long ans = 0;
long long n;
bool cmp1(node x,node y){
	return x.d1 > y.d1;
}
bool cmp2(node x,node y){
	if(x.d1 < x.d2) swap(x.d1,x.d2);
	if(x.d2 < x.d3) swap(x.d2,x.d3);
	if(y.d1 < y.d2) swap(y.d1,y.d2);
	if(y.d2 < y.d3) swap(y.d2,y.d3);
	if(x.d1 == y.d1){
		if(x.d2 == y.d2){
			return x.d3 > y.d3;
		}
		return x.d2 > y.d2;
	}
	return x.d1 > y.d1;
}
bool cmp3(node x,node y){
	return x.d1+x.d2+x.d3 > y.d1 + y.d2 + y.d3;
}
bool cmp4(node x,node y){
	if(x.d1 < x.d2) swap(x.d1,x.d2);
	if(x.d2 < x.d3) swap(x.d2,x.d3);
	if(y.d1 < y.d2) swap(y.d1,y.d2);
	if(y.d2 < y.d3) swap(y.d2,y.d3);
	return x.d1+y.d2+x.d3 > y.d1 + x.d2 + y.d3;
}
bool cmp5(node x,node y){
	if(x.d1 < x.d2) swap(x.d1,x.d2);
	if(x.d2 < x.d3) swap(x.d2,x.d3);
	if(y.d1 < y.d2) swap(y.d1,y.d2);
	if(y.d2 < y.d3) swap(y.d2,y.d3);
	return (long long)x.d1*x.d2*x.d3 > (long long)y.d1 * y.d2 * y.d3;
}
long long dd[4];
long long jisuan(){
	long long sum = 0;
	dd[1] = dd[2] = dd[3] = 0; 
	for(long long i = 1; i <= n; i++){
		node x = a[i];
		long long k1 = 1,k2 = 2,k3 = 3;
		if(x.d1 < x.d2) swap(x.d1,x.d2),swap(k1,k2);
		if(x.d2 < x.d3) swap(x.d2,x.d3),swap(k2,k3);
		if(dd[k1] < n/2) dd[k1]++,sum += x.d1;
		else if(dd[k2] < n/2) dd[k2]++,sum+=x.d2;
		else dd[k3]++,sum+=x.d3;
	}
	return sum;

}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0); 
	long long t;
	cin >> t;
	while(t--){
		ans = 0;
		
		cin >> n;
		
		for(long long i = 1; i <= n; i++){
			cin >> a[i].d1 >> a[i].d2 >> a[i].d3;
		}
		if(n <= 200){
			for(long long i = 0; i <= n/2; i++){
				for(long long j = 0; j <= n/2; j++){
					for(long long k = 0; k <= n/2; k++){
						dp[i][j][k] = 0;
					}
				}
			}
			for(long long i = 0; i <= n/2; i++){
				for(long long j = 0; j <= n/2; j++){
					for(long long k = 0; k <= n/2; k++){
						if(i+j+k > n) continue;
						if(i) dp[i][j][k] = dp[i-1][j][k] + a[i+j+k].d1;
						if(j) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k] + a[i+j+k].d2);
						if(k) dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1] + a[i+j+k].d3);
					}
				}
			}
			for(long long i = 0; i <= n/2; i++){
				for(long long j = 0; j <= n/2; j++){
					long long k = n-i-j;
					if(k <= n/2) ans = max(ans,dp[i][j][k]);
				}
			}
			cout << ans << "\n";			
		}else{
			long long q = 0;
			for(long long i = 1; i <= n; i++){
				if(a[i].d2 != 0 || a[i].d3 != 0) q = 1;
			}
			if(!q){
				sort(a+1,a+n+1,cmp1);
				for(long long i = 1; i <= n/2; i++) ans += a[i].d1;
				cout << ans << "\n"; 
			}else{
				sort(a+1,a+n+1,cmp2);
				ans = max(ans,jisuan());
				sort(a+1,a+n+1,cmp3);
				ans = max(ans,jisuan());
				sort(a+1,a+n+1,cmp4);
				ans = max(ans,jisuan());
				sort(a+1,a+n+1,cmp5);
				ans = max(ans,jisuan());
				cout << ans << "\n";
			}
		}

	}

	return 0;
} 
