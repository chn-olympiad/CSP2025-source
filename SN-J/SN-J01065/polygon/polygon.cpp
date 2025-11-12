//SN-J01065 郭子羽 西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n,ans,len,a[110],cnt[210];
bool flag = 1;
void dfs(int x,int id,int mx,int sum){
//	if(len - x == n - id + 1){
//		int y = sum;
//		for(int i = id;i <= n;i++){
//			y += a[i];
//			cnt[a[i]]--;
//		} dfs(len,n,y);
//	}
	if(x == len){
//		cout << x << " " << id << " " << mx << " " << sum << "\n";
		if(sum > mx * 2) ans++;
		return ;
	} if(id > n) return ;
	dfs(x,id + 1,mx,sum);
	if(cnt[a[id]]){
		cnt[a[id]]--;
		dfs(x + 1,id + 1,max(mx,a[id]),sum + a[id]);
		cnt[a[id]]++;
	} return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; cnt[a[i]]++;
		if(a[i] != 1) flag = 0;
	} sort(a + 1,a + n + 1);
	if(n > 100 && flag){
		cout << n - 2;
		return 0;
	} 
	for(int i = 3;i <= n;i++){
		len = i; dfs(0,1,0,0);
	}
	cout << ans;
	return 0;
}//复杂度O(2^n)，预计40+，过3样例 
/*
5
1 2 3 4 5


3 6 5 12
3 6 5 11
3 6 5 10
3 5 4 9
3 6 4 9
3 6 5 10
3 6 5 9
3 5 4 8
3 6 4 8
3 6 5 8
3 5 4 7
3 6 4 7
3 4 3 6
3 5 3 6
3 6 3 6
*/
