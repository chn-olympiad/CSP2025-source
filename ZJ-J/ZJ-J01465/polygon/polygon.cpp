#include<bits/stdc++.h>
using namespace std;
int a[5005],s[5005],f[5005][10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	f[1][0]=2;
	for(int i=1;i<=a[1];i++) f[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=a[n]*2+1;j++) f[i][j]=(f[i-1][j]+f[i-1][max(0,j-a[i])])%998244353;
	int ans=0;
	for(int i=3;i<=n;i++)
		ans=(ans+f[i][a[i]*2+1])%998244353;
	printf("%d\n",ans);
	return 0;
}
//关注Just_A_Sentence(LuoguUid=502314)谢谢喵~o( =∩ω∩= )m
//8:36 过 T1
//8:45 过 T2
//8:52 过 T3 不是哥们，今年这啥啊？预估难度红红橙黄/红红橙绿
//9:03 T4有思路了，建一个stack记录目前多边形里最大的几条边，当可以构成多边形时直接通过排列组合算出栈顶木条以后的所有情况，然后弹出栈顶。看起来是对的，但时间复杂度无法证明，不管了，写了再说
//9:36 感觉假了
//10:00 下了会国际象棋，让脑子清醒一下，感觉还是要往DP想
//10:20 右边那哥们说了声F**k，乐
//10:47 有一个O(n^3)想法
//10:57 假了，主要考虑4边形以上怎么判断
//11:55 炸缸。T4大样例3，4过不去