#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[101];
int c, r;

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int num = n*m;
	for(int i=0; i<num; i++) scanf("%d", &a[i]);
	int score=a[0], pos=0;
	sort(a, a+num, cmp);
	for(int i=0; i<num; i++)
		if(a[i] == score)
		{
			pos = i;
			break;
		}
	c = pos/n + 1;
	if(c%2 == 1) r=pos%n + 1;
	else r=n - pos%n;
	cout << c << " " << r; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
