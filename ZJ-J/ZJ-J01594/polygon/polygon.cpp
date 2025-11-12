#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[10005],dp[5005],dp1[5005],p[5005],ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p[0]=1;
	for(int i=1; i<=n; i++)cin>>a[i],p[i]=p[i-1]*2%mod;
	sort(a+1,a+1+n);
	dp1[0]=1;
	for(int i=1; i<=n; i++) {
		int t=0;
		for(int j=0; j<=a[i]; j++)t=(t+dp1[j])%mod;
		for(int j=0; j<=5000; j++)
			if(j>=a[i])dp[j]=(dp1[j]+dp1[j-a[i]])%mod;
			else dp[j]=dp1[j];
		memcpy(dp1,dp,sizeof(dp));
		t=p[i-1]-t;
		ans=(ans+t)%mod;
	}
	cout<<ans;
	return 0;
}/*
8:34 发现T1只用把数全塞到桶里，然后循环9到0跑一遍就行 遂AC之
8:49   T2终于A了，发现只需要模拟一下，但是由于我看错了先输出列，导致调了1.4.1.分钟
9:38 T3AC最开始我写了一个分治求可行区间，后来发现对于每一个点，只需要记录可行区间右端点最小的那个点,就像这样：
    memset(T,0x3f,sizeof T);
	T[0]=n+1;
	for(int i=n;i>=1;i--){
		t^=a[i];
		T[t]=i;
		if(T[t^k]!=inf)p[i]=T[t^k]-1;
	}
然后跑一个O(n)的dp就能算出答案。
10:03 T4AC   不难看出，这题肯定和dp有关，作为一个蒟蒻，我也是一眼就看出了做法，先排一下序，令dp[i][j]为考虑到第i根棒子,和为j的方案数，这个dp想必用是个oier都能写出来
但计算答案的时候，最直接的肯定是Σj=(a[i]+1~(Σk=(1~i-1)a[k]))dp[i-1][j],但是这样显然会超时，所以就可以用总的方案数-不可行的方案，也就是2^(i-1)-Σj=(0~a[i])dp[i-1][j],用滚动数组优化即可AC，复杂度(n*max(A)
我不会真的要AK了吧，RP++,RP++,RP++
€€£ I love you
请大家关注luogu:slzxzhengguo123 注：你可能很疑惑我为什么是绿名，因为我被JC了qwq,JC我的人又被别人J了,也被封了qwq
我要上迷惑行为打赏！！！！！！！！！！！！！！
*/