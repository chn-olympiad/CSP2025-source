#include <bits/stdc++.h>
using namespace std;
char s[1000010],s1[1000010];
int n[1000010];
int j=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < sizeof(s); i++)
	{
		if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0')
		{
			s1[j] = s[i];
			j++;
		}
	}
	for(int i = 0; i < j; i++)
	{
		if(s1[i] == '1') n[i] = 1;
		else if(s1[i] == '2') n[i] = 2;
		else if(s1[i] == '3') n[i] = 3;
		else if(s1[i] == '4') n[i] = 4;
		else if(s1[i] == '5') n[i] = 5;
		else if(s1[i] == '6') n[i] = 6;
		else if(s1[i] == '7') n[i] = 7;
		else if(s1[i] == '8') n[i] = 8;
		else if(s1[i] == '9') n[i] = 9;
		else if(s1[i] == '0') n[i] = 0;
	}
	sort(n,n+j);
	for(int i = j-1; i >= 0; i--)
	{
		cout << n[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
