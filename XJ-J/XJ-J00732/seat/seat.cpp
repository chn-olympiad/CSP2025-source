#include<bits/stdc++.h>
using namespace std;
int a[15][15],s[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	int n,m,xiaor;
	cin>>n>>m;
	cin>>xiaor;
	s[0]=xiaor;
	int chang=n*m;
	for(int i=1;i<chang;i++)
	{
		cin>>s[i];
	}
	sort(s,s+chang,cmp);
	int l=0,f=1,j=1,i=1;
	while(1)
	{
			a[i][j]=s[l];
			l++;
			if(a[i][j]==xiaor)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			if(f==1)
			{
				i++;
			}
			else 
			{
				i--;
			}
			if(i>n)
			{
				i--;
				j++;
				if(f)
				f=0;
				else
				f=1;
			}
			else if(i<1)
			{
				i++;
				j++;
				if(f)
				f=0;
				else
				f=1;
			}
			
		}
	return 0;
 } 
