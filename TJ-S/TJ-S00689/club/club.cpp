#include <bits/stdc++.h>

using namespace std;

int t,n,a[1000005][3],b[1000005][3],minn[1000005],ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int c = (n+1) / 2;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
				minn[i] = min(minn[i],a[i][j]);
			}
			ans += minn[i];
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				b[i][j] = a[i][j] - minn[i];
			}
			sort(b[i]+1,b[i]+n+1);
		}
		for(int i = n - c;i <= n;i++){
			ans += b[i][1] + b[i][2] + b[i][3];
		}
		cout << ans << endl;
	}
	
	return 0;
}
