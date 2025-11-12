#include <bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,m,a[MAXN],score;
bool cmp(int x,int y)
{
	return x>y;
}
void next(int &x,int &y)
{
	if(x==1)
	{
		if(y%2==1)
			x++;
		else
			y++;
	}
	else if(x==n)
	{
		if(y==m)
			goto end;
		if(y%2==1)
			y++;
		else
			x--;
	}
	else
	{
		if(y%2==1)
			x++;
		else
			x--;
	}
	end:return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
			score=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int i=0;
	int x=1,y=1;
	while(a[++i]!=score)
		next(x,y);
	printf("%d %d",y,x);
	return 0;
}
