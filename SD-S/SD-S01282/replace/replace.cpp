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
pair < string , string > s[10005];
int n , q;
int main()
{
	// C replace
	// 纯暴力无优化 
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	read(n);
	read(q);
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> s[i].first >> s[i].second;
	}
	for(int i = 1 ; i <= q ; i++)
	{
		string t1 , t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length())
		{
			print(0);
			printf("\n");
			continue;
		}
		int fst = 0 , lst = t1.length() - 1;
		for(int j = 0 ; j <= lst ; j++)
		{
			if(t1[j] != t2[j])
			{
				fst = j;
				break;
			}
		}
		for(int j = t1.length() - 1 ; j >= 0 ; j--)
		{
			if(t1[j] != t2[j])
			{
				lst = j;
				break;
			}
		}
		//cout << fst << ' ' << lst << endl;
		int ans = 0;
		for(int pj = 1 ; pj <= n ; pj++)
		{
			for(int t = 0 ; t + s[pj].first.length() - 1 < t1.length() ; t++)
			{
				if(t > fst || (t + s[pj].first.length() - 1) < lst || (t + s[pj].first.length() - 1) >= t1.length())
				{
					continue;
				}
				//cout << ' ' << pj << ' ' << t << endl;
				bool y = 1;
				for(int rd = 0 ; rd < s[pj].first.length() ; rd++)
				{
					if(t1[t + rd] != s[pj].first[rd])
					{
						//cout << "  " << t + rd << ' ' << t << ' ' << t1[t + rd] << ' ' << s[pj].first[rd] << endl;
						y = 0;
					}
					if(t2[t + rd] != s[pj].second[rd])
					{
						//cout << "  " << t + rd << ' ' << t << ' ' << t1[t + rd] << ' ' << s[pj].second[rd] << endl;
						y = 0;
					}
				}
				ans += y;
			}
		}
		print(ans);
		printf("\n");
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
