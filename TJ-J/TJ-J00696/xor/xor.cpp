#include<bits/stdc++.h>
using namespace std;
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
#define endl '\n'

/*
仔细仔细再仔细！
认真认真再认真！

十年 OI 一场梦，不开 ll 见祖宗
30 分钟必须跳，文件核对别爆零
多找规律试暴力，别把满分当一切
*/

// 1058 期望 30
// 1141 id like to try earn it more but it failed :(
constexpr int N = 5e5 + 5;
int a[N],b[N];
void solveplus(){
	// 所有样例和性质 AB 
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int maxn = -1; 
	for(int i = 1;i <= n;i ++){
		b[i - 1] = 0;
		for(int j = i;j <= n;j ++){
			b[j] = b[j - 1] xor a[j];
		}
		int ans = 0,f = 0;
		for(int j = i; j <= n; j ++) {
			if((b[j] xor f) == k) {
				ans ++;
				f ^= k;
			}
		}
		maxn = max(maxn,ans);
	} 
	cout << maxn << endl;
	return ;
} 
signed main() {
	fileIO("xor");
	cin.tie(0),cout.tie(0);
	solveplus();
	return 0;
}

