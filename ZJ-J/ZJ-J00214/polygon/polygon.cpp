#include<bits/stdc++.h>
using namespace std;
int n,a[50005],mod=998244353,maxx;
long long ans,jc[50005],sum[50005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),maxx=max(maxx,a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
			jc[min(maxx+1,j+a[i])]+=sum[j],jc[min(maxx+1,j+a[i])]%=mod;
		for(int j=a[i]+1;j<=maxx+1;j++)
		{
			ans+=sum[j];
			ans%=mod;
			jc[min(maxx+1,j+a[i])]+=sum[j];
			jc[min(maxx+1,j+a[i])]%=mod;
		 } 
		for(int j=1;j<=maxx+1;j++)
			sum[j]+=jc[j],sum[j]%=mod,jc[j]=0;
		sum[a[i]]++;
//		for(int j=1;j<=maxx+1;j++) cout<<sum[j]<<' ';
//		cout<<"++"<<ans;
//		cout<<endl;
	}
	printf("%lld",ans);
	return 0;
}
/*
感觉无聊透了 
10min AC T1
30min AC T2
40min AC T3
1h10min AC T4
就这么AK了？
我其实感觉十分玄乎
这套卷子偏简单？
感觉红橙黄黄
就是还有2h20min不知道干啥了
下午还有S
但也没啥困意
不知道干什么ing
希望不要挂分吧
感觉T4时间复杂度确实难说
我代码要n方
ccf我爱你
让我卡过去吧！！！ 
估分100+100+100+[80,100]=[380,400]
我赢了
起码在J组是赢麻了
想着这一年来付出的努力
这回报不就来了吗
不敢说自己有多少多少天赋
但我起码付出过不少的努力
想着那些晚上流过的泪
在想着自己题单中一片片的绿
我现在感到无比的自豪
不敢写太多
因为人们都说
骄兵必败
我就是AK了又如何呢？
卷子简单
大家都简单
你AK了
也必会有很多大佬和你一样AK
现在最重要的
是调整好状态
努力迎接下午的S
全力以赴
想想下下周就要期中考了
社会还有好多没背
语文背的也不熟
不慌是不可能的
但这次OI成绩一定要打出来
尤其是S
J看看应该可以AK
反正自我感觉还不错 
行吧
就这样了
我再去测测大样例
试试再造几组看看
确保万无一失


一通检查又是30min
啥也没检查出来
中间还去上了个厕所
差点以为我T2WA了
结果发现我纯小丑 
还试了试最后一题的极限
0.2s
只能说AK概率有98%
真的啥也不想干了
还有1h30min 
睡觉吧


突然发现电脑上连谷歌都没有
小恐龙都玩不了
算了算了
继续睡吧


还有1h
刚刚突然发现一个错误
我jc和sum数组没有开ll
差点炸飞了
吓死我了 


又把freopen和ll检查了一遍
真的不想呆在这里了
好无聊啊怎么还有50min 


后大悔了
没带零食过来
想吃吃东西解闷都不行
真的是
怎么时间都不动啊
我快要无聊炸了！！！


太好了终于只剩30min了
又检查了一遍freopen
感觉看到了胜利的曙光


细节现在11：35
哈哈哈


算了不写了杂念就这么定型了吧
现在最后检查一遍差不多要收卷了
我还要把字节数抄一下 
债见了
下午债见

 
luogu：yechenguo 
*/
