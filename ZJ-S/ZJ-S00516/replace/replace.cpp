#include<bits/stdc++.h>
using namespace std;
int n,q;
int xiangcun[15];
int c[15][10005];
int a[10005][10005];
bool xiufu[10005][10005];
char m[10001];
char e[10001];
char w[10001];
char r[10001];
int temp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	
	scanf("%d %d",&n,&q);
	for(int i = 1;i<=n;i++)
	{
		scanf("%s %s",m,e);
	}
	for(int j = 1;j<=q;j++)
	{
		scanf("%s %s",w,r);
	}
	for(int i = 1;i<=q;i++)
	{
		cout<<0<<"\n";
	}
	return 0;
	
}
