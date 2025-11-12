#include<bits/stdc++.h>
using namespace std;
int i,j,k,s=0,a[500005],n,m,now=0,sum=0,z,x,y;
int yh(int a,int b)
{
	int h=1,c=0,w1=a,w2=b;
	while(a!=0&&b!=0)
	{
		if((a%2==1&&b%2==0)||(a%2==0&&b%2==1))
		{
			c+=h;	
		}
		else
		{
			if(a%2==1&&b%2==1)
			{
				w1-=h;
				w2-=h;	
			}
		}
		a/=2;
		b/=2;
		h*=2;
	}
	if(a==0)
	{
		c+=w2;
	}
	else
	{
		c+=w1;
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			s++;
			now=i+1;
		}
		else
		{
			y=a[i];
			for(j=i-1;j>=now;j--)
			{
			 	x=yh(a[j],y);
			 	y=x;
			 	if(x==k)
			 	{
			 		s++;
			 		now=i+1;
					break;
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
