#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//放个注释证明这是我自己写的  >:) 

struct Student
{
	int score,number;
};

bool cmp(Student x, Student y)
{
	return x.score > y.score;
}

Student s[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int m,n;
	cin >> m >> n;
	
	for (int i = 1; i <= m * n; i++)
	{
		cin >> s[i].score;
		s[i].number = i;
	}
	
	sort(s + 1, s + m * n + 1, cmp);
	
	//for (int i = 1; i <= m * n; i++)
	//{
	//	cout << s[i].score << " " << s[i].number << endl;
	//}
	
	int seat;
	int sn = 1, sm = 0;
	
	bool flag = 0;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sn = i;
			if (i % 2 == 0)
			{
				sm = m - j + 1;
			}
			else
			{
				sm = j;
			}
			//cout << sn << " " << sm << endl;
			if (s[(i - 1) * m + j].number == 1)
			{
				seat = i;
				flag++;
				break;
			}
		}
		if (flag)
		{
			break;
		}
	}
	
	cout << sn << " " << sm;
	return 0; 
} 
