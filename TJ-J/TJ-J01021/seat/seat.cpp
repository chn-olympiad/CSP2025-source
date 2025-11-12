#include<iostream>
using namespace std;
int a[10][10];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cin>>a[x][y];
		}
	}
	int qian=1;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
		{
			if(a[x][y]>a[1][1])
			qian++;
		}
	}
	if(x==10&&y==10)
	{
		if((a[1][1]/10)%2==0)
		{
			cout<<10-a[1][1]/10<<" ";
			cout<<a[1][1]%10;
		}
		else
		{ 
			cout<<10-a[1][1]/10<<" ";
			cout<<10-a[1][1]%10;
		}
	}
	else if(x==1&&y==1)
	{
		cout<<1<<" "<<1;
	}
	else
	{
		cout<<x-qian/x+1<<" ";
		if((qian/x)%2==0)
		{
			cout<<qian%x+1;
		}
		else
		{
			cout<<x-(qian%x)+1;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
