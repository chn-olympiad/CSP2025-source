#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{int x,id;}a[10005];
bool cmp(node x,node y){return x.x>y.x;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i].id<<" "<<a[i].x<<" "<<x<<" "<<y<<"\n";
		if(a[i].id==1){cout<<y<<" "<<x<<"\n";return 0;}
		if(y%2==1)x++;else x--;
		if(x==n+1)x=n,y++;
		if(x==0)x=1,y++;
		
	}
	return 0;
}
//CSP RP++
