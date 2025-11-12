#include<bits/stdc++.h>
using namespace std;
char c;
int n;
void qread(int &n)
{
	c=0,n=0;
	for(;c<'0'||'9'<c;c=getchar());
	for(;'0'<=c&&c<='9';n=n*10+c-'0',c=getchar());
}
int a[5010];
bool check(int x,int y)
{
	return x>y*2;
}
int dfs(int last,int val,int maxn)
{
	int c=check(val,maxn);
	for(int i=last+1;i<=n;i++)
	{
		c+=dfs(i,val+a[i],max(maxn,a[i]));
	}
	return c;
}
/*
int power[10];
int t=1;
for(int i=0;i<=9;i++,t*=2)
{
    power[i]=t;
}
int ST[5010][10];
int m=log2(n);
for(int i=1;i<=n;i++)
{
    ST[i][0]=a[i];
}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
	    ST[i][j]=max(ST[i][j-1],ST[i+power[j-1]][j-1]);
	}
}
*/
/*
l,r;
int len=log2((r-l)+1);
max(ST[l][len]
好好的ST表白写了……虽然不太正规，但是还是挺好的
啊啊啊啊啊！我的dfs到底是什么时间复杂度啊！！！！ 
*/
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	qread(n);
	for(int i=1;i<=n;i++)
	{
		qread(a[i]);
	}
	cout<<dfs(0,0,0);
	return 0;
}
/*
dfs时间复杂度不会算……
保守估计大概是100+100+60+68= 328吧
要是我这个dfs是n^2的时间复杂度那么就是100+100+60+100=360分了
好像达不到n^2，太慢了，还要所有都搜索完
等一下，我想出来了RMQ+前缀和的算法！！！！
写ST表！ 
真好
忘了ST表怎么写了…… 
画了一下搜索树，应该是n^2的时间复杂度，太好啦！！！ 
好像是2^n?
算了，好像还自带有个纸牌游戏，不知道能不能玩，会不会被判作弊 
嗯，大概310分吧 

windows写代码也没什么不好的，就是getchar_unlocked用不了了
快读其实没什么意义，就是这个给这个暴力多争取些时间而已 

啊啊啊啊啊！我的dfs删掉了 

dfs吃到保底了，但是时间复杂度还是不会算 
 
 太可惜了，fread快读忘了
 
 哈哈哈哈哈！！！！！！
 记成了11点结束考试，我可以写正解啦！！！ 
  
快把我扔上迷惑行为大赏！！！
洛谷uid：忘了，到时候我去失物招领 

真无聊……还有半个多小时结束考试 

《关于我的代码还没我写的闲话多这件事》
好像没有题可以打表……真无聊
*/
