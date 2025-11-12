#include <iostream>
#include <algorithm>
using namespace std;

long long stulist[10005];

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long Rscore;
	long long n, m;
	cin >> n >> m;
	for (int j = 0; j < n * m; ++j )
	{
		cin >> stulist[j];
	}
	Rscore = stulist[0];
	sort(stulist, stulist + n * m, cmp);
	
	long long Rseat;
	
	for (long long j = 0; j < n * m; ++j)
	{
		if (stulist[j] == Rscore)
		{
			Rseat = j;
		}
	}
	
	long long t = 0, x = 1, y = 1, sign = 0;
	while(t != Rseat)
	{
		if(sign == 0)
		{
			if(x == n)
			{
				y++;
				sign = 1;
			}else{
				x++;
			}
			t++;
		}else
		{
			if(x == 1)
			{
				y++;
				sign = 0;
			}else{
				x--;
			}
			t++;
		}
	}
	cout << y << " " << x;
	return 0;
}
