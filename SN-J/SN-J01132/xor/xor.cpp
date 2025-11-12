#include<bits/stdc++.h>
using namespace std;
long long a[1010101],sum[1010101],lst[2050505];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	int zh=0,ans=0;
	for(int i=1;i<=2050500;i++) lst[i]=-0x7fffffff;
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		int zhq=k^sum[i];
		zhq=lst[zhq];
		if(zhq>=zh) ans++,zh=i;
		lst[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}








/*
想出来了，但不想写，嘻嘻
随便写东西玩，搞别人心态，嘻嘻
反射的我被镜子拘押
他说他认输想要回家
右脑吵左脑谁知真假
矛与盾争锋没有时差
心里这场雨倾盆而下
撑伞是否算活在当下
哪片草坪被任意践踏
蹲下一看我在脚下
抓着神志醒不过来
夜色精彩
醉人徘徊
祂的轮廓记不起来 
写完了嘻嘻
纯唐氏贪心
半小时拿下 T1~T3
但是没写等于号调了 5min 啊啊啊啊
不管 T4 了睡觉去 
*/ 
