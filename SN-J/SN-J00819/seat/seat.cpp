#include<bits/stdc++.h>
std::ifstream cin("seat1.in");
std::ofstream cout("seat1.out");
int main(){
	int a,b,c,d,e,g=0,h=0,x,y;
	cin>>a>>b;
	c=a*b;
	long long as[c];
	for(int i=1;i<=c;i++)
	{
		cin>>d;
		as[i]=b;
	}
	e=as[1];
	for(int i=2;i<=c;i++)
	{
		int f;
		as[i]=f;
		if(f>e)
		{
			g++;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			h++;
			if(h==g)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
