//SN-J01181 高思童 西安滨河学校
#include<bits/stdc++.h>
using namespace std;
int x,y;
int c;
int cy[10000]={};
int k;
int m; 
int main()
{
	//freopen("seat1.in","r",stdin);
	//freopen("seat1.out","w",stdout);
	cin>>x>>y;
	for(int i=0;i<x*y;i++)
	{
		cin>>cy[i];
	}
	c=cy[0];
	sort(cy,cy+x*y,greater<int>());
	for(int i=0;i<x*y;i++)
	{
		if(c=cy[i])
		{
			m=k;
		}
	}
	if(x<=1&&y<=1)
	{
		cout<<1<<" "<<1;
		 return 0;
	}
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
