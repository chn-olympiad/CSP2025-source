#include<bits/stdc++.h>
using namespace std;
char s[1006];
int a[1000005],b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int n=0;
	int l=strlen(s);
	for (int i = 0; i < l; i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			n++;
			a[n]=s[i]-'0';
		}
	} 
	sort(a,a+n+1);
	for (int i = n; i >= 1; i--)
	{
		cout << a[i];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
