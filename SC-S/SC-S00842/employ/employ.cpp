//Just Sayori!!!
//csp 2025 rp++
//祝学长全部进 WC！
//祝大家全员一等奖！
//该不会就我一个拿不到 1= 吧
//救救我，独角仙先生
/*
毁黄金黎明，弑师弑友~~~
爱华斯附身，为法之书~~~
知世界大战，不管不顾~~~
为幻想杀手，创立学都~~~
为了自己的计划失忆上条
同意六级害死妹妹上万
隐瞒里幻欲灭口右火
不顾只眼杀死上条无数
后面忘了
要多儒雅才显得无辜！
*/
//freopen("employ.in","r",stdin);
//freopen("employ.out","w",stdout);
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <set>
#include <list>
#define ll long long
#define rnt register int
#define gr getchar
#define pr putchar
#define N 500005
#define M 998244353
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
void write(ll x)
{
	int top=0,stack[39];
	if (x<0) pr('-'),x=-x;
	do stack[++top]=x%10,x/=10;
	while (x);
	while (top) pr(stack[top--]^48);
}
int n,m,ans,cnt;
string s;
int c[N];
list<int> lt;
void dfs(int u,int k)
{
	if (n-k<m) return;
	if (u==n+1)
		return ans++,void();
	int len=lt.size();
	while (len--)
	{
		int y=lt.back();
		lt.pop_back();
		dfs(u+1,k+((s[u]=='0')||(c[y]<=k)));
		lt.emplace_front(y);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read(),cin>>s,s=" "+s;
	for (rnt i=1;i<=n;i++) c[i]=read(),lt.emplace_back(i);
	if (n<=12)
	{
		dfs(1,0),write(ans),pr(10);
	}
	else write(0),pr(10);
	return 0;
}
