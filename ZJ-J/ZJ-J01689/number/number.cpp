#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
short b[maxn],num=0;
char a[maxn];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]-'0'>=0&&a[i]-'0'<=9)
		{
			num++;
			b[num]=a[i]-'0';
		}
	}
	sort(b+1,b+1+num);
	for(int i=num;i>=1;i--)
	{
		putchar(b[i]+'0');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

