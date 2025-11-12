#include <bits/stdc++.h>
using namespace std;
struct node
{
	int tp,sc;
}
a[10005];
bool cmp(node a,node b)
{
	return a.sc>b.sc;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		a[i].tp=0;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].sc; 
	a[1].tp=1;
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;i++)
		if(a[i].tp)
		{
			id=i;
			break;
		}
	int c=(id+n-1)/n,t=id%n,r;
	if(t==0)
		t=n;
	if(c&1)
		r=t;
	else
		r=n-t+1;
	cout<<c<<" "<<r;
	return 0;
}
