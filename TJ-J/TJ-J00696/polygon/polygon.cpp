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

// 0940 dfs 40
// 1139 i cant earn anymore! 
constexpr int N	= 5e3 + 5;
int n,a[N];

int dfs(int id,int ot,int sum){
	if(ot == 0) return (sum > 2 * a[id] ? 1 : 0);
	int t = 0;
	for(int i = id + 1;i <= n;i ++){
		t += dfs(i,ot - 1,sum + a[i]);
	}
	if(n - ot >= 3) t += (sum > 2 * a[id] ? 1 : 0);
	return t;
}
signed main(){
	fileIO("polygon");
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	cout << dfs(0,n,0);
	return 0;
}
