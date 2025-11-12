#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int t[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int tmp=strlen(s);
	for(int i=0;i<tmp;i++)
		t[(int)(s[i])]++;
	for(char i='9';i>='0';i--)
	{
		while(t[i])
		{
			putchar(i);
			t[i]--;
		}
	}
	return 0;
}
