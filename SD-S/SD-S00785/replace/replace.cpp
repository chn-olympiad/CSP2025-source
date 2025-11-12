//50
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n" 
int n,q;
string s[200005][3];
string q1,q2;
int ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i][1] >> s[i][2];
	}
	while(q --){
		ans = 0;
		cin >> q1 >> q2;
		for(int i=1;i<=n;i++){
			int pos = q1.find(s[i][1]);
			if(pos == -1) continue;
			string tmp = q1.substr(0,pos);
			tmp += s[i][2];
			tmp += q1.substr(pos + s[i][1].size());
			ans += (tmp == q2);
		}
		cout << ans << endl;
	}
	return 0;
} 
//long long(unsigned long long?) 
//初始化(lazy=0/1,init()放在输入n下面)
//树剖t[x].val = val[id[l]] 
//差分约束n+1
//并查集init(0,n+1?)
//空间尽可能开8倍,是否需要双向边?差分约束多建多少条边,与0构成的边边权为几 
//__gcd() __int128 __builtin_popcount()
//自己检验freopen 
//对拍 
