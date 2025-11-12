#include<bits/stdc++.h>
using namespace std;

string s;
long long int a[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i; 
	cin >> s;
	for (i=0; i<s.size(); i++)
		if (s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	for (i=9; i>=0; i--)
		while (a[i]--)
			cout << i;
	return 0;
}
