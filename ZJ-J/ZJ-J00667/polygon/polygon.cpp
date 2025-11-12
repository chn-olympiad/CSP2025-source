#include<stdio.h>
#include<algorithm>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)

const int N=5e3+10,mod=998244353;

int n,a[N],dp[N][N];
long long ans=0;


int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	if(a[n]==1) {//全部都是1哦
		//C(3,n)+C(4,n)+C(5,n)+...+C(n,n)
		//列个杨辉三角?
		//O(n^2/2)也许可以过吧
		dp[0][0]=1;
		rep(i,1,n) {
			dp[i][0]=1;
			rep(j,1,i) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
		}
		rep(l,3,n) ans=(ans+dp[n][l])%mod;
		printf("%lld",ans);
		return 0;
	}
	printf("0");
	return 0;
}
//Welcome to our code (^.^)/
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")
//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")//freopen("")



//#Shang4Shan3Ruo6Shui4
/*
luogu uid: 你猜 
ummm……这里放游记吧，下午肯定没时间写游记，那就上午随便写写吧，等到公布代码再粘贴回去

Day 1:
?:?  醒了，不知道几点，就是睡不着，大概有0.5h~2h吧
06:07 起床
06:42 吃早饭
07:07 去考场，中间不知道在考场外等了多久，没带手表 
07:40 到机房，这里时间有点没记住，大概在这个时候左右 
07:53 先睡会
08:26 报密码时没听清，后来发现是把g打成了j
09:14 难度不对劲，T1 T2写好了(?)反正大样例过了，不管了
09:34 T3 没想到，应该是二分，但不知道check怎么写，先去瞅瞅T4，花了10min盲猜dp 
10:05 T4 给我弄傻了，回来先把T3 特殊性质AB 做了
10:30  AB性质应该没问题了，看看n<=1000
10:40 没想到，6 
10:46 写游记放松一下(?)
10:56 放松好了，继续做题 
11:00 大不对劲，样例没过，连输出都没了，重新做特殊性质AB 
11:02 没事了，是样例打开错了
11:03 没时间了，统统打暴力吧
11:05 精修游记
11:06 赶紧去打暴力啊
11:07 在此，我郑重地宣布——我是...... 
11:13 我特喵的，我打的暴力时间估算一下是O(n!*n^2) n<=10都炸，n<=10都属于特殊性质AB了，我还打个毛线球啊，输出个0得了，走了，再看T4 
11:14 精修游记ing...
11:20 真的得去看T4了 
11:22 先把ai=1的做了 
11:42 ai=1应该好了，急 
11:45 暴力也来不及打了啊啊啊啊 
11:47 去检查文件名，freopen,调试语句什么的，没时间打暴力了 
11:49 检查好了，接下来是最后的挣扎
11:50 我赌结果有0 
11:53 放弃挣扎，把剩余的运气送给下午吧
11:54 好想上厕所啊啊啊啊啊啊
11:55 突然发现T4字节数是前面3题加起来的2倍不止,eee
11:56 收拾东西，度秒如年 
*/
