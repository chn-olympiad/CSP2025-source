#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;

int n, q;
string s1[N], s2[N];
string t1, t2; 

signed main(){
	cin.tie(0) -> sync_with_stdio(0);
//	freopen("replace3.in", "r", stdin);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> t1 >> t2;
		int ans = 0, len = t1.size();
		for(int j = 1; j <= n; j++){
			int l1 = s1[j].size(), l2 = s2[j].size();
			if(l1 != l2)  continue;
			for(int k = 0; k + l1 - 1 < len; k++){
				if(t1.substr(k, l1) == s1[j]){
					string tmp = t1.substr(0, k) + s2[j] + t1.substr(k + l1, len - k + l1);
					if(tmp == t2)  ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
由题意应该是只能替换一次
记录一下 t1 和 t2 的最短连续不同串
再看 s1 s2 是否包含这两个不同串，且其他部分也完全相同 
对于题给数据范围，我甚至不能遍历一遍 t
根号算法？ log 算法？ O(1) 判断？
暴力走人吧  10pts都有点悬啊 
*/ 
