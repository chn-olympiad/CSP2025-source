#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,s[15][15],a[200],k2;
bool cmp(int x,int y)
{
	if(x>y) return 1;
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	int j=1,i=1,l=1;
	
	while(i<=n+1&&j<=m+1)
	{
		s[i][j]=a[l]; 
	
		l++;
		
		if(k2==0) j++;
		if(k2==1) j--;
		if(j>=m+1)
		{
			j--;
			i++;
			k2=1;
		}
		if(j<=0)
		{
			j++;
			i++;
			k2=0;
		}
		
	}

	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=m+1;j++)
		{
			if(s[i][j]==k)
			{
			cout<<i<<" "<<j;
			}
		
		}
	
	}
	
	return 0;
}
