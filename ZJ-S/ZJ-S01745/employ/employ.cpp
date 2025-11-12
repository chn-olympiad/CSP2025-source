#include<bits/stdc++.h>
using namespace std;
const int N=510;
const long long Mod=998244353;
int n, m;
int Lim[N], Ord[N];
bool Can[N];
bool cmp(int x, int y)
{
	return Lim[x]<Lim[y];
}
long long ans;
long long A(int n, int m)
{
	long long Res=1;
	for(int i=n-m+1;i<=n;i++)
		Res*=i, Res%=Mod;
	return Res;
}
void dfs(int x, int Kill, int Res)
{
	if(x>n)
		return ans+=(Res>=m), void();
	if(Res>=m)
		return ans+=A(n-x+1, n-x+1), void();
	for(int i=x;i<=n;i++)
	{
		swap(Ord[x], Ord[i]);
		bool IsGet=(Can[x] && Kill<Lim[Ord[x]]);
		dfs(x+1, Kill+(!IsGet), Res+IsGet);
		swap(Ord[x], Ord[i]);
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%1d", &Can[i]);
	for(int i=1;i<=n;i++)
		scanf("%d", &Lim[i]), Ord[i]=i;
	sort(Ord+1, Ord+n+1, cmp);
	dfs(1, 0, 0);
	printf("%lld", ans%Mod);
	return 0;
}
/*
尝试拿到 m=1和12点 和A 
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

好吧特点没时间拿了
最后一次参加s组了喵
希望能有好的成绩（希望我能进noip并且能拿到奖！ 
曼波！ 
*/
