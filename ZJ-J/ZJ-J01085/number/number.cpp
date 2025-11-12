#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main()	{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	char ch = getchar();
	while (ch != '\n')	{
		if (ch >= '0' && ch <= '9')	a[ch ^ 48]++;
		ch = getchar();
	}
	for (int i = 9; i >= 0; --i)	{
		for (int j = 1; j <= a[i]; ++j)	putchar(i ^ 48);
	}
	cout << endl;
	return 0;
}