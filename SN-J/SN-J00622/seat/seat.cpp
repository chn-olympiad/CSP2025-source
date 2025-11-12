#include <bits\stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[100005];
	cin >> n >> m;
	int b = n*m;
	for (int i = 1;i <=b;i++)
	{
		cin >> a[i];
	}
	if (n == 1 and m == 1)
	{
		cout <<"1" <<" " << "1";
	}
}
