#include<bits/stdc++.h>
using namespace std;
template < typename T > void read(T &Read_)
{
	Read_ = 0; char c = getchar(); bool sgn = 0;
	while(!isdigit(c)) { sgn |= (c == '-'); c = getchar(); }
	Read_ = c - '0'; c = getchar();
	while(isdigit(c)) { Read_ = (Read_ << 1) + (Read_ << 3) + c - '0'; c = getchar(); }
	if(sgn) { Read_ = -Read_; }
}
template < typename T > void print(T Print_)
{
	char st[30]; int top = 0;
	if(Print_ < 0) { putchar('-'); Print_ = -Print_; }
	do { st[++top] = Print_ % 10; Print_ /= 10; } while(Print_);
	while(top) { putchar(st[top--] + '0'); }
}
int n , m , k;
pair < pair < int , int > , long long > edge[1100005];
int edcnt = 0;
bool cmp(pair < pair < int , int > , long long > a , pair < pair < int , int > , long long > b)
{
	return a.second < b.second;
}
int to[10105];
int find(int x)
{
	return (to[x] == x ? x : to[x] = find(to[x]));
}
int main()
{
	// B road
	// 瞪半天只会特殊性质 A 
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	read(n);
	read(m);
	read(k);
	for(int i = 1 ; i <= m ; i++)
	{
		edcnt++;
		read(edge[edcnt].first.first);
		read(edge[edcnt].first.second);
		read(edge[edcnt].second);
	}
	for(int i = 1 ; i <= k ; i++)
	{
		int pid = n + i;
		int x;
		read(x);
		for(int j = 1 ; j <= n ; j++)
		{
			long long val;
			read(val);
			edcnt++;
			edge[edcnt].first.first = pid;
			edge[edcnt].first.second = j;
			edge[edcnt].second = val;
		}
	}
	int point = n + k;
	for(int i = 1 ; i <= point ; i++)
	{
		to[i] = i;
	}
	sort(edge + 1 , edge + edcnt + 1 , cmp);
	long long ans = 0;
	for(int i = 1 ; i <= edcnt ; i++)
	{
		int u = edge[i].first.first , v = edge[i].first.second;
		if(find(u) != find(v))
		{
			to[find(u)] = find(v);
			ans += edge[i].second;
		}
	}
	print(ans);
	return 0;
}
/*
zip password Ren5Jie4Di4Ling5% 
提交要求 
1. 在 D 盘根目录下创建文件夹 SD-S00001张三（准考证号 + 名字，中间无空格，注意是英文短杠） 
2. 下面放题目文件夹 
3. 题目文件夹只放对应题目的源程序 
*/
