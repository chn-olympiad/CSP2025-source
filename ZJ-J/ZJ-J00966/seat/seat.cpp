#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int id,ex;
}a[200];
bool cmp(node x,node y)
{
	return x.ex>y.ex;
}
int c;
int r;
int main(){
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i].ex;
		a[i].id = i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i].id == 1)
		{
			r = i;
			c = r%n == 0?r/n:r/n+1;
			if(r%(n*2) == 0)
			{
				r = 0;
			}
			else if(r%(n*2)<n)
			{
				r%=n;
			}
			else if(r%(n*2) == n)
			{
				r = n;
			}
			else
			{
				r = n+1-r%n;
			}
			cout<<c<<" "<<r;
			return 0;
		}
	}
	return 0;
}

