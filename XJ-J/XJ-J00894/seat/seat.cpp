#include <bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in ","r","stdin");
	freopen("seat.out","w","stdout");
	int n, m;
	cin >> n >> m;
	int a[0];
	cin >> a[0];
	cout << n * m << endl << a[0];
	if(a[1] > a[2] > a[3] > a[4] > a[n] - 1)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i <= 10; i++)
		{
			a[i]--;
			cout << a[i] << endl;
		}
	}
	cout << a[n] * (n * m);
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
