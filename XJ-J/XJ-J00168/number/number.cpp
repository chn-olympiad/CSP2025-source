#include<bits/stdc++.h>
using namespace std;

long long int i,num[10];
char s[1000000];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(i = 0;i < strlen(s);i++)
	{
		if(s[i] >= '0' && s[i] <= '9') num[s[i] - '0']++;
	}
	for(i = 9;i >= 0;i--)
	{
		while(num[i] != 0)
		{
			cout << i;
			num[i]--; 
		}
	}
	return 0;
}
