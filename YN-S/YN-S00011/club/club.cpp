#include <bits/stdc++.h>
using namespace std;

struct club {
	int a;
	int b;
	int c;
} student[100000];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, m, n, z;
	int clubs[3] = {};
	int cha[100000][3] = {};
	int max = 0;
	clubs[0] = 0;
	clubs[1] = 0;
	clubs[2] = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
		;
	{
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> student[j].a >> student[j].b >> student[j].c;
		}
		for (int j = 0; j < n; j++) {
			if (student[j].a > student[j].b && student[j].a > student[j].c)
				;
			{
				clubs[0]++;
				max = max + student[j].a;
				if (student[j].b > student[j].c)
					;
				{
					cha[j][0] = student[j].a - student[j].b;
				}
				if (student[j].c > student[j].b)
					;
				{
					cha[j][0] = student[j].a - student[j].c;
				}
			}
			if (student[j].b > student[j].a && student[j].b > student[j].c)
				;
			{
				clubs[1]++;
				max = max + student[j].b;
				if (student[j].a > student[j].c)
					;
				{
					cha[j][1] = student[j].b - student[j].a;
				}
				if (student[j].c > student[j].a)
					;
				{
					cha[j][1] = student[j].b - student[j].c;
				}
			}
			if (student[j].c > student[j].b && student[j].c > student[j].a)
				;
			{
				clubs[2]++;
				max = max + student[j].c;
				if (student[j].b > student[j].a)
					;
				{
					cha[j][2] = student[j].c - student[j].b;
				}
				if (student[j].a > student[j].b)
					;
				{
					cha[j][2] = student[j].c - student[j].a;
				}
			}
		}
		for (int j = 0; j < 3; j++) {
			while (clubs[j] > n / 2) {
				for (int x = 0; x < n; x++) {
					for (int y = 1; y < n; y++) {
						if (cha[y][j] < cha[x][j])
							z = cha[x][j];
						cha[x][j] = cha[y][j];
						cha[y][j] = z;
					}
				}
				for (int x = 0; x < n; x++) {
					max = max - cha[x][j];
					clubs[j]--;
				}
			}
		}
		cout << max;
	}
	return 0;
}