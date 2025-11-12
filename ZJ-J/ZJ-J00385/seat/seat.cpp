#include<bits/stdc++.h.>
using namespace std;
int n,m,a,x,y,num,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	if(n==1&&m==1)
	{
		cout<<a;
		return 0;
	}
	for(int i=2;i<=m*n;i++)
	{
		cin>>s;
		if(s>a) num++;
	}
	if(n==1)
	{
		cout<<num+1<<' '<<1;
		return 0;
	}
	if(m==1)
	{
		cout<<1<<' '<<num+1;
		return 0;
	}
	x=1;y=1;s=0;
	while(num>0)
	{
		num--;
		if(s==0&&y==n)
		{
			s=1;
			x++;
			continue;
		}
		if(s==1&&y==1)
		{
			s=0;
			x++;
			continue;
		}	
		if(s==0) y++;
		if(s==1) y--;
	}
	cout<<x<<' '<<y;
	return 0;
}