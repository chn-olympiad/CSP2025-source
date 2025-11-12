//SN-J00325 张奕晨 西安市建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],nm,f=0,c1=0,c2=0;
	cin>>n>>m;
	nm=n*m;
	for(int i=0;i<nm;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<nm;i++)
	{
		if(a[i]>a[0]) f++;
	}
	if((f/m)%2==0)
	{
		c1=(f/m)+1;
		c2=(f%m)+1;
		if(c1<0) c1=c1-c1-c1;
		if(c2<0) c2=c2-c2-c2;
		cout<<c1<<' '<<c2;
	}
	else
	{
		if(n-(f%m)+1==1)
		{
			c1=(f/m)+1;
			c2=n;
			if(c1<0) c1=c1-c1-c1;
			if(c2<0) c2=c2-c2-c2;
			cout<<c1<<' '<<c2;
			return 0;
		}
		c1=(f/m)+1;
		c2=n-(f%m)+1;
		if(c1<0) c1=c1-c1-c1;
		if(c2<0) c2=c2-c2-c2;
		cout<<c1<<' '<<c2;
	}
	return 0;
}
