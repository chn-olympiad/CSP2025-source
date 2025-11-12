#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	char s = 0;
	cin >> s;
	int a;
	a=(1, 2, 3, 4, 5, 6, 7, 8, 9);
	char zhong;
	for(int i = 0; i <= 10; i++)
	{
		if(s == a && s != 0)
		{
			s++;
			cout << s;
		}
		else
		{
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
