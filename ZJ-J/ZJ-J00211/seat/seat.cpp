#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=0,m=0,t=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	t=a[0];
	for(int i=n*m-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	int k=0;
	while(a[k]!=t)
	{
		k++;
	}
	k++;
	int x=0,y=0;
	int a=k%(2*n);
	int b=k/(2*n);
	if(a==0)
	{
		x=b*2;
		y=n;
	}
	else if(a<=n)
	{
		x=b*2+1;
		y=a;
	}
	else
	{
		x=b*2+2;
		y=2*n-a+1;
	}
	cout<<x<<" "<<y<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
 } 
