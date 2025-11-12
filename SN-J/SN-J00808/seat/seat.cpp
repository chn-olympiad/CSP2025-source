#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int a[m*n+5];
	for (int i = 1; i<= m*n ; i++)
	{
		cin >> a[i];
	}
	int tmp = a[1];
	sort(a,a+m*n+1);
	int save;
	for (int i = 0 ;i<=m*n+5;i++)
	{
		if (a[i]==tmp)
		{
			save = m*n-(i+1)+1;
		}
	}
	if (save%n==0 && (save/n)%2==1) cout << save/n << " " << n;
	else if (save%n==0 && (save/n)%2==0) cout << save/n << " " << 1;
	else if (save%n!=0 && (save/n+1)%2==1) cout << save/n+1 << " " << save%n;
	else if (save%n!=0 && (save/n+1)%2==0) cout << save/n+1 << " " << n-(save%n)+1;
	return 0;
}
