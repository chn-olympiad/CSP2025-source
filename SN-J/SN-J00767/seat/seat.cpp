// 王梓宇 SN-J00767 西安市曲江第二中学
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, X, C, R;
struct Student
{
	int id, cheng, zuo;
} a[101];
bool cmp(Student x, Student y)
{
	return x.cheng > y.cheng;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin >> N >> M;
	for (int i = 1;i <= N * M;++i)
	{
		a[i].id = i;
		cin >> a[i].cheng;
	}
	sort(a + 1, a + N*M + 1, cmp);
	for (int i = 1;i <= N*M;i++)
	{
		a[i].zuo = i;
		if (a[i].id == 1)
			X = a[i].zuo;
	}
	if (X % M == 0)
		R = X / M;
	else 
		R = X / M + 1;
	if (R % 2 == 1)
		C = X - (R-1) * M;
	else 
		C = N + 1 - (X - (R-1) * M);
	cout << R << " " << C;
	return 0;
}
