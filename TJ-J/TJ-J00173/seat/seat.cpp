#include<bits/stdc++.h>
using namespace std;
int j=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l,r,a[100]={},s=0,d=0,z=0,q=0,w=0,e=0;
	cin>>l>>h;
	cin>>r;
	for(int i=0;i<l*h-1;i++)
	{
		cin>>a[i];
		q++;
	}
	for(int i=0;i<q-1;i++)
	{
		for(int j=0;j<q-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				w=a[j];
				a[j]=a[j+1];
				a[j+1]=w;
			}
		}
		
	}
	s=l;
	if(l%2==0)
	{
		l=l/2;
		for(int j=0;j<l;j++)
		{
//			int d=0;
			for(int y=0;y<h;y++)
			{
				if(a[d]<r)
				{
					cout<<1<<endl;
					printf("%d %d",j*2+1,y+1);
					
					e++;
					break;
				}
				
				d++;
			}
			for(int y=h;y>0;y--)
			{
				if(a[d]<r)
				{
					cout<<2<<endl;
					printf("%d %d",(j+1)*2,y);
					e++;
					break;
				}
				
				d++;
			}
			
		}
	}
	else
	{
		l=l/2;
		for(j=0;j<l;j++)
		{
			for(int y=0;y<h;y++)
			{
				if(a[d]<r)
				{
					cout<<3<<endl;
					printf("%d %d",j*2+1,y+1);
					e++;
					break; 
				}
				
				d++;
			}
			for(int y=h;y>0;y--)
			{
				if(a[d]<r)
				{
					cout<<4<<endl;
					printf("%d %d",(j+1)*2,y);
					e++;
					break;
				}
				
				d++;
			}
		}
		for(int y=0;y<h;y++)
		{
			if(a[d]<r)
			{
				cout<<5<<endl;
				printf("%d %d",j*2+1,y+1);
				e=1;
				break;
			}				
			d++;
		}
		
	}
	if(e==0)
	{
		cout<<6<<endl;
		printf("%d %d",s,h);
	}
	return 0;
}
