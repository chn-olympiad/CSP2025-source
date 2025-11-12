/*
StarLight_Yuran_ovo
last day last day last day~
今天不是明天
JROI 2023~无限
Starlight OI 2024~无限
RP++
648647291436
*/
#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
string s;
int c[N];
int vis[N];
int ans;
void dfs(int x,int cnt)
{
	if(x>n)
	{
		if(cnt>=m)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if((c[i]>x-1-cnt)&&(s[x-1]=='1'))
			{
				dfs(x+1,cnt+1);
			}
			else
			{
				dfs(x+1,cnt);
			}
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
第一次考复赛。S 组及其的倒闭。下个赛季继续努力吧。J 组别挂分窝要 5 级勾！！！顺带一提：感谢善良的监考老师给我这个初来乍到的路痴带路去厕所！ 
我们再无分离。
在此祝即将退役的朋友 @Pyrf_uqcat 一路繁花。虽然这个机位键盘及其不好使但还是要努力打出这些字！
*/
