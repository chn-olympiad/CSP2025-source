#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int nums[12];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			nums[s[i] - '0'] ++;
		}
	}
	for(int i = 0;i < nums[9];i ++)
	{
		cout << 9;
	}
	for(int i = 0;i < nums[8];i ++)
	{
		cout << 8;
	}
	for(int i = 0;i < nums[7];i ++)
	{
		cout << 7;
	}
	for(int i = 0;i < nums[6];i ++)
	{
		cout << 6;
	}
	for(int i = 0;i < nums[5];i ++)
	{
		cout << 5;
	}
	for(int i = 0;i < nums[4];i ++)
	{
		cout << 4;
	}
	for(int i = 0;i < nums[3];i ++)
	{
		cout << 3;
	}
	for(int i = 0;i < nums[2];i ++)
	{
		cout << 2;
	}
	for(int i = 0;i < nums[1];i ++)
	{
		cout << 1;
	}
	for(int i = 0;i < nums[0];i ++)
	{
		cout << 0;
	}
	return 0;
}
