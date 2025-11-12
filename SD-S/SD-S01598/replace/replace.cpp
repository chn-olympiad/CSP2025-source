/*
Solution:
给定n个二元字符串组
考虑对于每个问题二元字符串组
有多少个t1替换得到t2的方式
直接考虑暴力
对于t1爆搜那些可以换，dfs换，换到不能再换为止，出现t2就结束 
但是有可能爆栈 
不是怎么读错题了
怎么只能换一次
直接枚举起点
再枚举换为哪一个
check换完后一不一样就行了 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+7,M=1e6+7;
int n,q,ans=0,len;
string s1[N],s2[N];
string t1,t2;
bool check_same(string s)//判断s是否=t2 
{
	if(s.size()!=t2.size()) return 0;
	for(int i=0;i<len;i++)
	    if(s[i]!=t2[i])
		   return 0;
    return 1;
}
string work(string s,int pos,int k)//将s从第pos位往后替换为sk2 
{
	for(int i=pos;i<pos+s1[k].size();i++)
	{
		if(s[i]!=s1[k][i-pos])
		{
			string aa;
			aa[0]=' ';
			return aa;
		}
		s[i]=s2[k][i-pos];
	}
	return s;
}
int dfs(string s)//s变到t2的方法数 
{
	long long ans=0;
	for(int i=0;i<len;i++)//枚举x 
	{
	 	for(int j=1;j<=n;j++)//枚举用哪个变化 
 		{
		 	string s2=work(s,i,j);
		 	if(check_same(s2))
		 	{
		 		ans++;
		    }
	    }	
	}
	return ans;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t1>>t2;
		len=t1.size();
		if(len!=t2.size())
		{
			cout<<0<<'\n';
			continue;
		}
		cout<<dfs(t1)<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
