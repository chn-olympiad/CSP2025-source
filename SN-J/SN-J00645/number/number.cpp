//SN-J00645 杨陈泽 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
string s;
int a[50];
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if((s[i] - '0') >= 0 && (s[i] - '0') <= 9)
		{
			a[s[i] - '0']++; 
		}
	}
	for(int i = 9 ; i >= 0 ; i--)
	{
		while(a[i]--)
		{
			cout << i;
		}
	}
	return 0;
}
