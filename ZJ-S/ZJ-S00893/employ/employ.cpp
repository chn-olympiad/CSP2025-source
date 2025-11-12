#include <bits/stdc++.h>
using namespace std;
/*
感觉要 AFO 了
抱歉，最亲爱的小x
抱歉，每一个祝福过我的人
抱歉，帮助过我的长辈、老师、同学和网友
大概这就是朽木不可雕吧 
天生我材必有用的前提是是材 
 
感谢 CCF 出题组
现在由衷地感觉我的存在不仅地狱而且笑话 

AB 写了三个小时还没写出来
一开始看到 A，傻了
看了看 B，感觉可做，看了数据范围，傻了
早上 J 组 C 也不会，我就是个废物吧
毕竟也属于是初三了，哎。 

而且我还不是一般的 jocker
我替前主导打工勤勤恳恳搞了两个月 OI
工作日尽量保持着每天 10 题的水准
也在模拟赛里切过一两次蓝
但是有用吗？
正赛的时候，各种心悸手抖，心态直接炸了
脑子里不知道装的什么
 
我甚至没有想过我到底喜欢 OI 还是 whk
虽然大概都不喜欢，我讨厌内卷 
但是这 60 天还是很少为自己想过
可能我在玩的游戏里面真正喜欢的只有原神

打算再骗点分就走了。
可能我天生就没有什么优点吧。
期望得分：J 300+，S 0 
 
再见，小 x。 
再见，OI ？ 

by @fly_x (luogu)
*/ 

// while(rp++);

#define int long long 
const int mod = 998244353;
int n, m, ans, c[505]; char s[505]; bool v[505];
void dfs(int i, int sum, int los){
	if (m-sum < n-i) return; 
	if (i > n){
		if (sum >= m) (++ans) %= mod;
		return ;
	}
	for (int j = 1; j <= n; j++)
		if (!v[j]){	v[j] = 1;
			if (los >= c[j] || s[i] == '0') dfs(i+1, sum, los+1);
			else dfs(i+1, sum+1, los);
			v[j] = 0;
		}
} 
signed main(){
    freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s+1; 
    for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c+1, c+n+1);
    if (n <= 18) dfs(1, 0, 0);
    else if (m == 1){
    	int res = 0;
    	for (int i = 1; i <= n; i++)
    		if (s[i] == '0') ++res;
    		else break;
		ans = 1; __int128 x = 1, y = 1;
    	for (int i = 1; i <= n; i++)
    		if (c[i] >= res){
    			(ans += x) %= mod;
    			(x *= y) %= mod, ++y;
			}
	} 
	else if (m == n){
		c[0] = -1; 
		__int128 res = 0;
		for (int i = 1, x; i <= n; i++){
			if (c[i] == c[i-1]) ++x, (res *= x) %= mod;
			else (ans += res) %= mod, res = x = 1;
		}
	} else{
		ans = 1;
		for (int i = 1; i <= n; i++)
			(ans *= i) %= mod;
	}
	cout << ans;
//    for (int i = 1; i <= n; i++)
//    	if ()
    return 0;
}

