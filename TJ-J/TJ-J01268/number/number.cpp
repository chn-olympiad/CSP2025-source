#include<bits/stdc++.h>
using namespace std;
string s;
long long len;
int a[10], num[10];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.length();
	for(int i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			int x = s[i] - '0';
			num[x]++;
		}	
	} 
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 1; j <= num[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
} 
