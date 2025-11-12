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

// 0905 AC O(nm) = 100
// 1141 i cant earn it anymore!
constexpr int N = 105;
int a[N];
 
int calc(int x,int y){
	return (x % y == 0 ? y : x % y);
}
signed main(){
	fileIO("seat"); 
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i];
	} 
	int r = a[1];
	sort(a + 1,a + n * m + 1,greater<int>());
	int s = 0;
	for(int i = 1;i <= n * m;i ++){
		if(a[i] == r){
			s = i;
			break;
		}
	}
	// 先列后行 
	int val = (int)ceil(s * 1.0 / n);
	cout << val << " ";
	if(val % 2 == 1)cout << calc(s,n);
	else cout << n - calc(s,n) + 1;
	return 0;
}

