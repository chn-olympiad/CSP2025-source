#include<bits/stdc++.h>
char a[1000006];
char b[1000006];
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=strlen(a);
	int s=0;
	for(int i=0;i<=len-1;i++)
	{
		if(a[i]>='0' and a[i]<='9')
		{
			b[++s]=a[i];
		}
	}
	sort(b+1,b+s+1);

	for(int i=s;i>=1;i--)
	{
		cout<<int(b[i])-48;
	}
	
	return 0;
}
