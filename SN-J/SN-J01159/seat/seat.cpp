//SN-J01159  马启源   西安市曲江第一中学
#include<bits/stdc++.h>
using namespace std;
int x,y;
int c;
int cp[10000]={}; 
int xt,yt;//小R的坐标 
int i;//排序后小R的名次 
int m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>x>>y;
	for(int i=0;i<x*y;i++)
	{
		cin>>cp[i];
	}
	
	c=cp[0];
	
	sort(cp,cp+x*y,greater<int>());
	
//	for(int i=0;i<x*y;i++)
//	{
//		cout<<cp[i];
//	}
	
	if(x<=1&&y<=1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	
	for(int i=0;i<x*y;i++)
	{
		if(c==cp[i])
		{
			m=i;
		}
	}
	//cout<<m;
	if(m<x)
	{
		cout<<1<<" "<<m+1;
		return 0;
	}
	 
	if(m<2*x)
	{
		cout<<2<<" "<<2*x-m-1;
		return 0;
	}
	
	if(m<3*x)
	{
		cout<<3<<" "<<m-2*x+1;
		return 0;
	}
	
	if(m<4*x)
	{
		cout<<4<<" "<<4*x-m-1;
		return 0;
	}
	
	if(m<5*x)
	{
		cout<<5<<" "<<m-4*x+1;
		return 0;
	}
	
	if(m<6*x)
	{
		cout<<6<<" "<<6*x-m-1;
		return 0;
	}
	
	if(m<7*x)
	{
		cout<<7<<" "<<m-6*x+1;
		return 0;
	}
	
	if(m<8*x)
	{
		cout<<8<<" "<<8*x-m-1;
		return 0;
	}
	if(m<9*x)
	{
		cout<<9<<" "<<m-8*x+1;
		return 0;
	}
	
	if(m<10*x)
	{
		cout<<10<<" "<<10*x-m-1;
		return 0;
	}
	
	return 0;
 } 
 
