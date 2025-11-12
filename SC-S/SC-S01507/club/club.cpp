//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10005] ,b[10005] ,c[10005];
bool cmp(int x, int y){
	return x > y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0) ;
	int T; cin >> T;
	while(T --) {
		memset(a ,0,sizeof(a)) ;
		memset(b ,0,sizeof(b)) ;
		memset(c ,0,sizeof(c)) ;
		int n; cin >> n;
		bool flag = 0;
		for(int i=1;i <= n;i ++) {
			cin >> a[i] >> b[i] >> c[i] ;
			if(b[i]!= 0 || c[i]!= 0) flag = 1;
		}if(flag== 0){
			sort(a+1, a+1 +n,cmp) ;
			int ans = 0;
			for(int i= 1;i <= n/2;i ++) ans += a[i]; 
			cout << ans << "\n";
		}
		else if(n == 2){
			int x[4] = {a[1] ,b[1] ,c[1]},y[4] = {a[2] ,b[2] ,c[2]};
			sort(x ,x+n ,cmp); sort(y ,y +n ,cmp) ;
			int ans =  max(x[0] + y[1] ,x[1] + y[0]) ;
			cout << ans << "\n" ;
		} 
	}
	return 0;
}
