#include <bits/stdc++.h>
using namespace std;

int a[10006], sum = 0;
string s;
bool cmp(int x, int y)
{
	return x < y;
}
int main()
{
	freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout); 
	cin>>s;
	int flag = 0; 
	for (int i=0; i<s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[i] = s[i] - '0';
			flag++;
		}
	}
	sort(a, a + flag + 1, cmp);
	for (int i=flag; i>=0; i--)
	{
		sum += a[i] * pow(10, i);
	}
	cout<<sum / 10;
	return 0;
}
