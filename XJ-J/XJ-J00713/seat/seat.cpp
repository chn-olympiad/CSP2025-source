#include<bits/stdc++.h>
using namespace std;
int a[105];
int flag[15][15];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,len,l,h;
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int flagR=a[1];
	sort(a+1,a+len+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++)//有m列考生 
	{//可以按奇偶性看，奇数列从上往下，偶数列从下往上
		if(i%2==1)//奇数 
		{
			for(int j=1;j<=n;j++)//每列有n个学生
			{//从上往下 
				flag[i][j]=a[k];
				k++;
			}
		}
		else//偶数 
		{
			for(int j=n;j>0;j--)
			{
				flag[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(flag[i][j]==flagR)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}//50分---20分 
