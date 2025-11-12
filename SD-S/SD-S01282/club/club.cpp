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
int t;
int n;
struct num
{
	pair < long long , long long > arr[3];
	num()
	{
		arr[0].first = arr[0].second = arr[1].first = arr[1].second = arr[2].first = arr[2].second;
	}
};
long long cost[100005];
num a[100005];
bool check(int numa , int numb , int numc)
{
	return (numa <= n / 2) && (numb <= n / 2) && (numc <= n / 2);
}
int num[4];
long long change[100005];
long long calc(int pos)
{
	memset(change , 0 , sizeof(change));
	for(int i = 1 , j = 1 ; i <= n ; i++)
	{
		if(a[i].arr[2].second == pos)
		{
			change[j++] = cost[i];
		}
	}
	sort(change + 1 , change + num[pos] + 1);
	int need = num[pos] - n / 2;
	long long delta = 0;
	for(int i = 1 ; i <= need ; i++)
	{
		delta -= change[i];
	}
	return delta;
}
void solve()
{
	read(n);
	for(int i = 1 ; i <= n ; i++)
	{
		read(a[i].arr[0].first);
		read(a[i].arr[1].first);
		read(a[i].arr[2].first);
		a[i].arr[0].second = 1 , a[i].arr[1].second = 2 , a[i].arr[2].second = 3;
		sort(a[i].arr , a[i].arr + 3);
		cost[i] = a[i].arr[2].first - a[i].arr[1].first;
	}
	num[0] = num[1] = num[2] = num[3] = 0;
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		ans += a[i].arr[2].first;
		num[a[i].arr[2].second]++;
	}
	if(num[1] > n / 2)
	{
		ans += calc(1);
	}
	if(num[2] > n / 2)
	{
		ans += calc(2);
	}
	if(num[3] > n / 2)
	{
		ans += calc(3);
	}
	print(ans);
	printf("\n");
	for(int i = 1 ; i <= n ; i++)
	{
		a[i].arr[0].first = a[i].arr[1].first = a[i].arr[2].first = 0;
		a[i].arr[0].second = a[i].arr[1].second = a[i].arr[2].second = 0;
		cost[i] = 0;
	}
}
int main()
{
	// A club 
	// 抛去一个人后不可能有多于一个是满人状态 
	// 所以只要一个人有两个最优可选项就能随便选 (wa)
	// priority_queue 维护退到下一个最优可选项的代价最小的人 (wa)
	// 只把最多的一个的一部分人退到下一个最优可选项即可 
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	read(t);
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
zip password Ren5Jie4Di4Ling5% 
提交要求 
1. 在 D 盘根目录下创建文件夹 SD-S00001张三（准考证号 + 名字，中间无空格，注意是英文短杠） 
2. 下面放题目文件夹 
3. 题目文件夹只放对应题目的源程序 
*/
