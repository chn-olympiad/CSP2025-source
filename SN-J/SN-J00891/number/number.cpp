//SN-J00891  耿峥钊  西安辅轮中学 
#include <bits/stdc++.h>
using namespace std ;
int a[100005] , num;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s ;
	for (int i = 0 ; i < s.length() ; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[i] += s[i] - '0';
			num++ ;
		}
	}
	sort(a + 1,a + num + 1) ;
	for (int i = 0 ; i < num ; i++)
	{
		cout << a[i] ;
	}
	return 0 ;
}
