#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int up(int x,int y)
{
	if(x%y!=0)
		return x/y+1;
	return x/y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	int R=a[1],posR;
	sort(a+1,a+1+t,cmp);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==R)
		{
			posR=i;
			break;
		}
	}
	int col=up(posR,n),li=posR%n;
	if(li==0)
		li=n;
	if(col%2==0)
		li=n-li+1;
	cout<<col<<" "<<li;
	return 0;
}
