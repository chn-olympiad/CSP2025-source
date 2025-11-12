#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500;
int n,m;
struct node
{
	int x,q;
}a[N];
bool cmp(node r,node t)
{
	return r.x>t.x;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int v=n*m;
	a[1].q=1;
	for(int i=1;i<=v;i++)
	{
		cin>>a[i].x;
	}
	sort(a+1,a+v+1,cmp);
	for(int i=1;i<=v;i++)
	{
		if(a[i].q==1)
		{
			if(i%n==0)
			{
				if((i/n)%2==0)
				{
					cout<<i/n<<' '<<n-i+1;
				}
				else
				{
					cout<<i/n<<' '<<i;
				}
			}
			else if((i/n)%2==0)
			{
				cout<<i/n+1<<' '<<i%n;
				return 0;
			}
			else
			{
				cout<<i/n+1<<' '<<n-i%n+1;
			}
			return 0;
		}
	}
	return 0;
} 
