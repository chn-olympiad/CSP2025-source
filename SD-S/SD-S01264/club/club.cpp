#include <bits/stdc++.h>
using namespace std;

int n, a[100005][4], ifA, ifB, nk;

int sss[100005], dp[210][210][210];

void special_A()
{
    for (int i = 1; i <= n; i ++) sss[i] = a[i][1];
	sort (sss + 1, sss + n + 1);
	int sum = 0;
	for (int i = 1; i <= (n >> 1); i ++)
	{
		sum += sss[i];
	}	
	cout << sum << endl;
	return ;
}

void _mian_()
{
	cin >> n;
	ifA = 1;
	ifB = 1;
	for (int i = 1; i <= n; i ++) 
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][2] != 0) ifA = 0;
		if (a[i][3] != 0)
		{
			ifA = 0;
			ifB = 0;
		}
	}
	if (ifA) {
		special_A();
		return ;
	}
	for (int i = 0; i <= (n >> 1); i ++)
	    for (int j = 0; j <= (n >> 1); j ++)
	        for (int k = 0; k <= (n >> 1); k ++)
	            dp[i][j][k] = 0;
	for (int i = 0; i <= (n >> 1); i ++)
		for (int j = 0; j <= (n >> 1); j ++)
		    for (int k = 0; k <= (n >> 1); k ++)
		    	if (i + j + k <= n)
		    	{
		    		if (i != 0) dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k] + a[i + j + k][1]);
		    		if (j != 0) dp[i][j][k] = max (dp[i][j][k], dp[i][j - 1][k] + a[i + j + k][2]);
		    		if (k != 0) dp[i][j][k] = max (dp[i][j][k], dp[i][j][k - 1] + a[i + j + k][3]);
				}
	int maxx = 0;
	for (int i = 0; i <= (n >> 1); i ++)
	{
		for (int j = 0; j <= (n >> 1); j ++)
		{
			for (int k = 0; k <= (n >> 1); k ++)
			{
				if (i + j + k != n) continue; 
			    maxx = max (maxx, dp[i][j][k]);
			}
		}
	}
	cout << maxx << endl;
	return ;
}

int main()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);  
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int T;
    cin >> T;
    while (T --)
    {
    	_mian_();
	}
	return 0;
}
/*
先诈骗一下嘻嘻

//freopen feropen froepen freeopen frepoen 

freopen ("club.in", "R", stdin);
freopen ("club.out", "W", stdout);  

初二蒟蒻第一次考csp-s。

预计得分：

60+64+25+8=157pts 燃尽了

第二题还给我卡了，第三个大样利一直在0.99xx ms到1.0xxx ms 之间徘徊（什么都没改）

第四个大样利直接不对

woc，我第二题好像解法有问题 现在只有44 分了 

只有137分吗。。。没事，下次努力吧

别告诉我137分连2=都没有 我感觉可能1= 

整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活整活 

球上迷惑行为大赏QWQ，其他三篇代码也是 

luogu uid:787512（很菜的蒟蒻，非luogu名字）

王者名：秋月（可加好友，名字不含括号和括号内的内容） 

祝在座的各位把把出刀 把把顶级！



         A                  FFFFFFFFFF               O O O        
		A A                 F                      O       O
	   A   A                F                    O          O
	  A     A               F                   O            O
	 A       A              F                  O              O
	AAAAAAAAAAA             FFFFFFFFF          O              O
   A           A            F                   O            O
  A             A           F                     O        O
 A               A          F                       O  O O      I
A                 A way     F        rom       

xjhichliebedich 

CSP-S 2025 邮寄

## 10/31 

上了 $G3170$（火车）前往日照，约 $13$ 点到达。

和同学两位 bro 吃了铁板烧，约好一起打游戏。

回山外文元酒店。一个 bro 订的亲子房，和我与另一位 bro 不同楼层。

回房间大约 $16$ 点，接受木琴思想教育半小时。

另一位 bro 已经睡了，只能自己玩 QWQ。

醒了之后去找 bro 玩了一会儿，然后吃饭了。 

然后去史迹。另两位 bro 都是要么只考 J 要么都考。先走了。

我去史迹碰见了两位 bro，都考的那一位说去了就能史迹。

拿上资料跑了个400，问题不大。一分半吧，不是很快，状态不好。 

回来之后木琴失踪了。上前台打电话。木琴强忍怒火。

回房间继续接受半小时思想教育。

## 11/1

早上起来先接受半小时思想教育（所有思想教育都是以昨天，10/31 的事儿为题材的，上下同）。

吃饭。比全季好太多了。

回酒店，打游戏。没意思。

下国际象棋。

吃饭。

大概 $12$ 点了。睡觉。

$2$ 点开始收拾，木琴太慢了。最后两点十分才走。

沿途继续接受思想教育。

考试。

T1暴力骗分。T2同。T3同。T4同。总之：四个暴力

135pts，挂了。

（剩下的回洛谷接着写） 
*/
