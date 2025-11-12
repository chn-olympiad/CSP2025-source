#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c;
void delete_alpha()
{
	for (int i = 1;i <= c.length();i++)
	{
		if (c[i] < '0' or c[i] > '9') c[i] = '\0';
	}
}
bool cmp(char a,char b)
{
	return b < a;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	delete_alpha();
	char c_c[c.length() + 3]; 
	memset(c_c, 0, sizeof(c_c));
	for (int i = 1;i <= c.length();i++)
	{
		c_c[i] = c[i - 1];
	}
	sort(c_c + 1,c_c + c.length() + 1,cmp);
	for (int i = 1;i <= c.length();i++)
	{
		cout << c_c[i];
	}
	return 0;
	
} 
