//SN-J00833 白敬轩 西安高新一中沣东中学 
#include<bits/stdc++.h>
using namespace std;
int seat[15][15],a[105],n,m,num,ansn,ansm,x=1;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j = 1;j <= m;j++)
	{	
		if(j % 2 == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				seat[i][j]=a[x];
				x++;
				if(seat[i][j]==num)
				{
					cout << j <<" "<< i;
					return 0;
				}
			}
		}
		if(j % 2 == 0)
		{
			for(int i = n;i >= 1;i--)
			{
				seat[i][j]=a[x];
				x++;
				if(seat[i][j]==num)
				{
					cout << j <<" "<< i;
					return 0;
				}
			}
		}
		
	}
		
} 
