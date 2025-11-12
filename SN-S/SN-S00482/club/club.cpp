//王子铭 SN-S00482 西安市曲江第一中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t --){
		int n;
		int key = 1,mx = -1;
		cin >> n;
		vector<int> a(n+1,0),b(n+1,0),c(n+1,0);
		for(int i = 1;i <= n;i ++){
			cin >> a[i] >> b[i] >> c[i];
			mx=max(a[i],mx);
			if(b[i]!=0){
				key = 0;
			}
		}
		if(key){
			cout << mx << "\n";
		}
	}
	return 0;
} 
