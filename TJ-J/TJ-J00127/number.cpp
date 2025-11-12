#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000];
	scanf("%s",s);
	int l=strlen(s);
	int num[l];
	for(int i=0;i<l;i++)
	{
		num[i]=10;
	}
	for(int i=0;i<l;i++)
	{
		int p=s[i];
		if(p>=48&&p<=57)
		{
			num[i]=p-48;
		}
	}
	sort(num,num+l,cmp);
	for(int i=0;i<l;i++)
	{
		if(num[i]!=10) cout<<num[i];
	}
	return 0;
}
