#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout); 
	int n,m,i=1,j;
	int a[105],flag=0;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int z=a[1],b=1,f=0;
	sort(a+1,a+n*m+1,cmd);
	for(j=1,i=1;j<=m;)
	{
		for(;;) 
		{
//			cout<<"i:"<<i<<" j:"<<j<<"B:"<<b<<endl;
			if(i>n)
			{
				i=n;
				flag=1;
				break;
			} 
			if(i<1) 
			{
				i=1;
				flag=0;
				break;
			}
			zw[i][j]=a[b];
			if(a[b++]==z)
			{
				cout<<j<<" "<<i;
				break;
			}
//			f=1;
			if(flag==1) i--;
			else i++;	

		}
		j++;
	}
	
//	for(i=1;i<=n;i++)
//	{
//		cout<<endl;
//		for(j=1;j<=m;j++)
//		{
//			cout<<zw[i][j]<<" ";
//		}
//	}
	return 0;
}
