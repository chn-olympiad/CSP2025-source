#include<bits/stdc++.h>
using namespace std;
struct node{
	int chen;
	int hao;
};
node c[200];
int cmp(node o,node p)
{
	return o.chen>p.chen;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>c[i].chen;
		c[i].hao=i;
	}
	sort(c+1,c+1+n*m,cmp);
	int x=1,y=1,z=1;
	for(int i=1;i<=n*m;i++)
	{
		if(c[z].hao==1)
		    break;
		if(y%2==1)
		    x++;
		if(y%2==0)
		    x--;
		if(x<1)
			x++,y++;
		if(x>n)
			x--,y++;
		z++;
	}
	cout<<y<<" "<<x;
}
