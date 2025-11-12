#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt;
int szzh(char k)
{
	if(k == '0') return 0;
	else if(k == '1') return 1;
	else if(k == '2') return 2;
	else if(k == '3') return 3;
	else if(k == '4') return 4;
	else if(k == '5') return 5;
	else if(k == '6') return 6;
	else if(k == '7') return 7;
	else if(k == '8') return 8;
	else if(k == '9') return 9;
	else return -1;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.length();i++)
	{
		if(szzh((char)s[i]) != -1)
		{
		a[i] = szzh((char)s[i]);
		cnt++;
		}
	}
	sort(a,a+s.length());
	reverse(a,a+s.length());
	for(int i = 0;i<cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
