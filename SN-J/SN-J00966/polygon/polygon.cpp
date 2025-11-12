//SN-J00966  袁浩文  西安辅轮中学
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int a[5005],n,sum,ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=(1<<n)-1;i++){
		int cnt=i,mmax=-inf,cc=0,ctn=0;
		for(int j=1;j<=n;j++){
			if(cnt%2==1){
				cc+=a[j];
				ctn++;
				mmax=max(a[j],mmax);
			}
			cnt>>=1;
		}
		if(cc>mmax*2&&ctn>=3)ans=(ans+1)%998244353;
	}
	cout<<ans;
	return 0;
}
/*
sto lrs orz
sto wyr orz
qjy orz
wbh orz
lzh orz
hhz orz
四位大佬rp分我一点（bushi）
8:11
ccf求你了出点简单题吧qwq
8:18
补豪线段树板子忘了咋写了
直接AFO得了
8:20
去年freopen没加分号J爆零了，今年是不可能爆零的
去年太菜了没参加S
8:22
文化课差的要命，OI又学的一塌糊涂
炸了
8:28
我补药回去学文化课
连NOIP都没去过
我太菜了
要开考了
J争取AK
8:47
T1水飞
8:57
T2水飞
9:01
666T3没看出来咋做
但是T4应该是DP
9:02
补豪是01背包
太好了没复习
ccf I love you
9:07
不是01背包
我就说咋可能这么简单
算了先看T3
9:16
诶T4就是个背包吧
n^3 5000过得去吗
9:24
好家伙大样例得自己出
那我出了我也不知道对不对啊
ccf I love you
9:27
这背包不对劲啊
9:29
补豪想假了
9:33
有人会吗
我不想就拿200走人
但tm真不会啊
ccf I love you
9:35
T3应该能骗60
666我J都AK不了可以直接AFO了
9:53
完了完了T3骗分写假了
9:58
颓吧颓吧考完就AFO了
10:05
算了特殊性质30分吧
10:09
666特殊性质都能写挂
T3黄/橙啊woc这我过不去
原地AFO
10:17
666特殊性质又写挂了
10:20
OK特殊性质写完（但估计只有10分）
10:24
sb异或，gun
10:30
仅剩一个半小时
T4能写40分的吧
11:04
OK现在算下来是有250分了，大抵是够了
11:14
摆了摆了
11:17
qwq
11:21
我为什么要写这个？？？ 
算了写了都写了
11:22
开颓开颓
11:25
今年题比去年简单
但我为什么只有250
555我太菜了
11:34
YHW12345 I love you*/
