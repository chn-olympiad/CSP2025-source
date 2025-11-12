#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long goal_num;
long long score[105];
bool cmp(long long x,long long y)
{
	return x > y;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	long long total = n * m;
	for(int i = 1;i <= total;i++)
	{
		scanf("%lld",&score[i]);
	}
	long long goal = score[1];
	sort(score + 1,score + total + 1,cmp);
	for(int i = 1;i <= total;i++)
	{
		if(score[i] == goal)
		{
			goal_num = i;
		}
	}
	long long goal_j;
	if(goal_num % n != 0)
	{
		goal_j = goal_num / n + 1;
	}
	else
	{
		goal_j = goal_num / n;
	}
	long long goal_i;
	if(goal_j % 2 == 1)
	{
		long long start_1 = (goal_j - 1) * n + 1;
		for(int i = start_1;i <= start_1 + n - 1;i++)
		{
			if(score[i] == goal)
			{
				if(i % n == 0)
				{
					goal_i = n;
				}
				else
				{
					goal_i = i % n;
				}
			}
		}
	}
	else
	{
		long long end = goal_j * n;
		long long tmp;
		for(int i = end - n + 1;i <= end;i++)
		{
			if(score[i] == goal)
			{
				if(i % n == 0)
				{
					tmp = n;
				}
				else
				{
					tmp = i % n;
				}
			}
		}
		long long cnt = 0;
		for(int i = end;i >= end - n + 1;i--)
		{
			cnt++;
			if(cnt == tmp)
			{
				if(i % n == 0)
				{
					goal_i = n;
				}
				else
				{
					goal_i = i % n;
				}
			}
		}
	}
	cout << goal_j << " " << goal_i;
	return 0;
}
