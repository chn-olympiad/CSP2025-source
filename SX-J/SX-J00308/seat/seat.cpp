#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<int> pq;
ll n,m,a[10005],tp;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		pq.push(a[i]);
	}
	tp=a[1];
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(pq.top()==tp)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				else
				pq.pop();
			}
		}
		else
		{
 			for(int j=n;j>=1;j--)
			{
				if(pq.top()==tp)
				{
					cout<<i<<" "<<j;
					return 0;
				}
				else
				pq.pop();
			}
		}
	}
	return 0;
}