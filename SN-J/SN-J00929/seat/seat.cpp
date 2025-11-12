/*
SN-J00929
董国栋
西安市曲江第一学校 
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],me,x,y,id;
bool cmp(int a1,int a2)
{
	return a1>a2; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	me=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(id=1;a[id]!=me;id++);
	x=id/n+(id%n!=0);
	if(x&1)
	{
		if(id%n==0)
			y=n;
		else
			y=id%n;
	}
	else
	{
		if(id%n==0)
			y=1;
		else
			y=n-id%n+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
