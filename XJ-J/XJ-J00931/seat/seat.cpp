#include <bits/stdc++.h>
using namespace std;
struct A{
	int id,f;
}a[210];
bool cmp(A x,A y)
{
	return x.f>y.f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].f;
		cnt++;
		a[i].id=cnt;
	}
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			pos=i;
		}
	}
	int q=(pos-1)/n+1,w=(pos-1)%n+1;
	if(q%2==0)
	{
		w=m-w+1;
	}
	cout<<q<<" "<<w;
	return 0;
}
