//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define mid (l+r>>1)
using namespace std;
const int N=501,mod=998244353;
int n,m,ans,a[N],f[1<<18][19];
char s[N];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
void add(int &x,int y) { (x+=y)>=mod&&(x-=mod); }
main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),scanf("%s",s);
	for (int i=0;i<n;i++) a[i]=read();
	if (m==n) {
		for (int i=0;i<n;i++)
		if (!a[i]||s[i]=='0') return !putchar('0');
		ans=1; for (int i=1;i<=n;i++) ans=1ll*ans*i%mod;
		return !printf("%d",ans);
	}
	f[0][0]=1;
	for (int S=0;S<1<<n;S++)
	{
		int cnt=__builtin_popcount(S);
		for (int i=0;i<=cnt;i++) if (f[S][i])
			for (int j=0;j<n;j++) if (!(S>>j&1) )
				add(f[S|(1<<j)][i+(i>=a[j]||s[cnt]=='0')],f[S][i]);
	}
	for (int i=0;i<=n-m;i++)
	add(ans,f[(1<<n)-1][i]);
	return !printf("%d",ans);
}
/*
形式化的，对于所有排列 p
从前往后扫一遍 
若 cnt>=c[p[i] ] 或 s[i]=0，则将 cnt++ 
求 cnt<=n-m 的个数  
首先我会 O(2^n*n^2)
m=n，若不存在 c=0 或 s=0，答案为 n!，否则为 0
能不能转成 Hall 定理啊
事已至此，先写 T3 吧 
18:10 过掉了样例 1 和样例 2 
*/ 
