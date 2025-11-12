#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
int re();
void wr(int x);
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=re(),m=re();
	for(int i=1;i<=m;i++)
	{
		wr(0);
		putchar('\n');
	}
	return 0;
}
int re()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void wr(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)
	{
		wr(x/10);
	}
	putchar(x%10+'0');
}

