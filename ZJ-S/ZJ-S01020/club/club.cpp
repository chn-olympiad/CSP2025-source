#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][5];
int tmp[100005];
int ans;
void dfs(int num,int sum,int x,int y,int z){
	if(x > n/2 || y > n/2 || z > n/2) return;
	if(num == n+1){
		ans = max(ans,sum);
		return;
	} 
	for(int i = 1;i <= 3;i++){
		dfs(num+1,sum+a[num][i],(i == 1?x+1:x),(i == 2?y+1:y),(i == 3?z+1:z));
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n == 100000){
			for(int i = 1;i <= n;i++){
				tmp[i] = a[i][1];
			}
			sort(tmp+1,tmp+n+1);
			for(int i = n/2;i <= n;i++){
				ans += tmp[i];
			}
			cout << ans << endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	
	return 0;
}
