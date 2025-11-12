#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int n;
ll a[5005];
int cnt;

void dfs(int i, int z, ll maxx, ll num){
	if(i == n + 1){
		if(z >= 3 && num > maxx * 2) cnt ++;
		return;
	}
	for(int f = 1;f <= 2;f++){
		if(f == 1){
			dfs(i + 1, z, maxx, num); 
		}else{
			dfs(i + 1, z + 1, max(maxx, a[i]), num + a[i]);
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cnt = 0;
	dfs(1, 0, 0, 0);//下标 选几个 最大值 总和 
	cout << cnt;
	return 0;
}


