#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll score[100003],n,m,R_pos,r,c;
ll R_score;
bool cmp(int x,int y)
{
	return y < x;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;//n为行数m为列数 
	cin >> R_score;
	score[1] = R_score;
	for (int i = 2;i <= n * m;i++)
	{
		cin >> score[i];
	}
	sort(score + 1,score +  n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++)
	{
		if (score[i] == R_score)
		{
			R_pos = i;
		}
	}
	//cout << R_pos << " "; 
	c = ceil(1.0 * R_pos / m);
	if (c % 2)
	{
		r = R_pos % n;
		if (r == 0) r = n;
	}
	else r = n - (R_pos % n) + 1;
	cout << c << " " << r;
	return 0;
} 
