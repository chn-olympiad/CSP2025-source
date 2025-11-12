#include <bits/stdc++.h>
using namespace std;

struct student
{
	long long number,node;
}st[101];

bool cmp(student a,student b)
{
	return a.number > b.number;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i = 1;i <= n * m;i++)
	{
		cin >> st[i].number;
		st[i].node = i;
	}
	sort(st + 1,st + n * m + 1,cmp);
	long long my = 0;
	for(long long i = 1;i <= n * m;i++)
	{
		if(st[i].node == 1)
		{
			my = i;
			break;
		}
 	}
 	long long resn = (my - 1) / n + 1;
 	long long resm = my % n;
 	if(!resm)
 	{
 		resm = n;
	}
	cout << resn << " " << resm;
	return 0;
}
