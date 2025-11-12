//高梓轩-SN-J01186-西安建筑科技大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int x,y,n,b;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y>>n;
	for(int i=0;i<x*y-1;i++)
	{
		cin>>a[i];
	}
	sort(a,a+(x*y-1));
	for(int i=0;i<x*y-1;i++)
	{
		if(n>a[i])
		{
			b=i;
			break;
		}
		b=i;
	}
	int h=0,l=0;
	if(b%x==0) l=b/x;
	else l=b/x+1;
	if(l%2==0) h=b%l;
	else h=5-(b%y);
	cout<<l<<h;
	
	return 0;
}
