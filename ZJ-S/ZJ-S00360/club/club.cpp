#include <bits/stdc++.h>
#define int long long
using namespace std;

struct student
{
	int t[3];
};

int n;
student slist[200000];

int maxindex(student A)
{
	if (A.t[0] >= A.t[1] && A.t[0] >= A.t[2])
		return 0;
	if (A.t[1] >= A.t[0] && A.t[1] >= A.t[2])
		return 1;
	if (A.t[2] >= A.t[0] && A.t[2] >= A.t[1])
		return 2;
}

int minindex(student A)
{
	if (A.t[0] <= A.t[1] && A.t[0] <= A.t[2])
		return 0;
	if (A.t[1] <= A.t[0] && A.t[1] <= A.t[2])
		return 1;
	if (A.t[2] <= A.t[0] && A.t[2] <= A.t[1])
		return 2;
}

int midindex(student A)
{
	int maxn = maxindex(A);
	int minn = minindex(A);
	for (int i = 0; i <= 2; i++)
	{
		if (maxn != i && minn != i)
			return i;
	}
	return 0;
}

bool cmp(student A, student B)
{
	int avalue = A.t[maxindex(A)] - A.t[midindex(A)];
	int bvalue = B.t[maxindex(B)] - B.t[midindex(B)];
	return avalue > bvalue;
}

int once()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> slist[i].t[j];
		}
	}
	sort(slist, slist + n, cmp);
	//cout << "===" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << slist[i].t[j] << " ";
//		}
//		cout << endl;
//	}
//	
	int clubs[3] = {0, 0, 0};
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (clubs[maxindex(slist[i])] < n / 2)
		{
			ans += slist[i].t[maxindex(slist[i])];
			clubs[maxindex(slist[i])]++;
		}
		else if (clubs[midindex(slist[i])] < n / 2)
		{
			ans += slist[i].t[midindex(slist[i])];
			clubs[midindex(slist[i])]++;
		}
//		else
//		{
//			cout << "ERROR" << endl;
//		}
	} 
	cout << ans << endl;
	
	
	return 0;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)	
	{
		once();
	}
	return 0;
} 
/*
1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042

OUTPUT: 125440
*/
