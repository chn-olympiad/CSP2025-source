#include<cstdio>
using namespace std;
const int maxl=10;
int f[maxl];
char c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(true)
	{
		c=getchar();
		if(c>='a'&&c<='z')continue;
		else if(c>='0'&&c<='9')f[c^48]++;
		else break;
	}
	for(int i=9;i>=0;i--)
		while(f[i]--)
			putchar(i^48);
	return 0;
}
