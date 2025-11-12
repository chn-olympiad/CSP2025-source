#include <bits/stdc++.h>
using namespace std;
int n,m,goal,x,y;
int a[105];
bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	goal = a[1];
	sort(a+1,a+1+n*m,cmp);
	bool f = 1;
	x=1;y=1;
	for(int k = 1;k<=n*m;k++)
	{
		if(y > m)
		{
			f = !f;
			x++;
			y = m;
		}
		else if(y<1)
		{
			f = !f;
			x++;
			y =1;
		}
		if(a[k] == goal)
			break;
		if(f)
			y++;
		else
			y--;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
