#include<bits/stdc++.h>
using namespace std;
string s;
int hx[11];
int sum = 0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin >> s; 
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] >= '0' and s[i] <= '9')
		{
			hx[int(s[i] - '0')]++;
		}
	}
	for(int i = 9;i >= 1;i--)
	{
		for(int j = 1;j <= hx[i];j++)
		{
			cout << i;
			sum++;
		}
	}
	if(sum == 0) 
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= hx[0];i++) cout << 0;
	return 0;
}
//fugriuoghfiughhhhhhhhiuhg
