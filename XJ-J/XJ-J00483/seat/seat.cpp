#include<bits/stdc++.h>
using namespace std;
long long int a[109],b[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	long long int n,m,i,len,k=0,me,x,yu,y;
	cin>>n>>m;
	len=n*m;
	for(i=1;i<=len;i++)
	cin>>a[i];
	me=a[1];
	sort(a+1,a+1+len); 
	for(i=len;i>=1;i--)
	b[++k]=a[i];
	
	for(i=1;i<=len;i++)
	{
		if(me==b[i])
		{
			x=ceil(i*1.0/n);
			
			yu=i%n;
			if(x%2==0)
			{
				y=n+1-yu;
			}
			if(x%2!=0)
			{
				if(yu==0) 
				y=n;
				else
				y=yu;
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
 
