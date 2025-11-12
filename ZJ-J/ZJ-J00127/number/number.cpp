#include<bits/stdc++.h>
using namespace std;

char s[1000005];
int a[20];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> s + 1;
	int n = strlen(s + 1);
	for(int i = 1;i <= n;i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[s[i] - '0'] = a[s[i] - '0'] + 1;
		}
	}
	for(int i = 9;i >= 0;i--)
	{	
		while(a[i] > 0)
		{
			cout << i;
			a[i]--;
		}
	}
	return 0;
}