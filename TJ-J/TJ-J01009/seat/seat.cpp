#include<iostream>
using namespace std;

int a[110];
int n,m,x,y,cnt=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
			cnt++;
	}
	
	
	if(cnt%n==0)
	{
		y=cnt/n;
		y%2==0?x=1:x=n;
		//if(y%2==0)
		//	x=1;
		//else
		//	x=n;
	}
	else
	{
		y=cnt/n+1;
		y%2!=0?x=cnt%n:x=n-cnt%n+1;
		//if(y%2!=0)
		//	x=cnt%n;
		//else
		//	x=n-cnt%n+1;

	}
	
	
	cout<<y<<" "<<x;
	
	return 0;
}



