#include <bits/stdc++.h>
using namespace std;
int n, ans, sum;
int a[500005], b[500005], c[500005];
void dfs(int i, int aa, int bb, int cc){
	if(i > n){
		ans = max(ans,sum);
		return;
	}
	if(aa < n/2){
		sum += a[i];
		dfs(i+1,aa+1,bb,cc);
		sum -= a[i];
	}
	if(bb < n/2){
		sum += b[i];
		dfs(i+1,aa,bb+1,cc);
		sum -= b[i];
	}
	if(cc < n/2){
		sum += c[i];
		dfs(i+1,aa,bb,cc+1);
		sum -= c[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T --){
		cin >> n;
		int pA = 1, pB = 1;
		for(int i = 1;i <= n;i ++){
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0 || c[i] != 0)pA = 0;
			if(c[i] != 0)pB = 0;
		}
		ans = 0, sum = 0;
		if(n <= 10){
			dfs(1,0,0,0);
			cout << ans << endl;
		}
		else if(pA){
			sort(a+1,a+n+1);
			for(int i = n;i > n/2;i --)ans += a[i];
			cout << ans << endl;
		}
		else {
			int aa = 0, bb = 0, cc = 0;
			for(int i = 1;i <= n;i ++){
				if(max({a[i],b[i],c[i]}) == a[i]){
					if(aa < n/2){
						aa ++;
						ans += a[i];
					}else {
						if(max(b[i],c[i]) == b[i]){
							bb ++;
							ans += b[i];
						}else {
							cc ++;
							ans += c[i];
						}
					}
				} else if(max({a[i],b[i],c[i]}) == b[i]){
					if(bb < n/2){
						bb ++;
						ans += b[i];
					}else {
						if(max(a[i],c[i]) == a[i]){
							aa ++;
							ans += a[i];
						}else {
							cc ++;
							ans += c[i];
						}
					}
				} else {
					if(cc < n/2){
						cc ++;
						ans += c[i];
					}else {
						if(max(b[i],a[i]) == b[i]){
							bb ++;
							ans += b[i];
						}else {
							aa ++;
							ans += a[i];
						}
					}
				}
			}
			cout << ans;
		}
	}
	return 0;
}
