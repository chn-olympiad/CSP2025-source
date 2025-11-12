//郭子羽 SN-S00716 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int T,n,ans,a[210][5],x,b[100010];
void dfs(int x,int y,int z,int sum){
	if(x + y + z == n){
		ans = max(ans,sum);
		return ;
	}
	int id = x + y + z + 1;
	if(x < n / 2) dfs(x + 1,y,z,sum + a[id][1]);
	if(y < n / 2) dfs(x,y + 1,z,sum + a[id][2]);
	if(z < n / 2) dfs(x,y,z + 1,sum + a[id][3]);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T; while(T--){
		cin >> n;
		if(n > 200){ ans = 0;
			for(int i = 1;i <= n;i++){
				cin >> b[i] >> x >> x;
			} sort(b + 1,b + n + 1);
			for(int i = n;i > n / 2;i--){
				ans += b[i];
			} cout << ans;
		}else{
			for(int i = 1;i <= n;i++){
				cin >> a[i][1] >> a[i][2] >> a[i][3];
			} ans = 0;
			dfs(0,0,0,0);
			cout << ans << "\n";
		}
	}
	return 0;
}
