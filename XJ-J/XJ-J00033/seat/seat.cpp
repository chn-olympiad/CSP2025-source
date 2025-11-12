#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,m,r; 
int a[105]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdin);
	int i,j,cnt=1,x=1,y=1,k=1,len;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			len=i;
		}
	}
	for(i=1;i<=len;i++)
	{	
		if(x==n&&y<m)
		{
			k=0;
			y=y+1;
		}
		else if(x==1&&y<m)
		{
			k=1;
			x=1;
			y=y+1;
		}
		else if(k==1&&x<n)
		{
			x++;
		}
		else if(k==0&&x>1)
		{
			x--;
		}
	}	
	cout<<x<<" "<<y;
	return 0;
 } 
 // 94 95 96 97 98 99 100 93 92
