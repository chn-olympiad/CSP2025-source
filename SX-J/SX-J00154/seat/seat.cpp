#include<bits/stdc++.h>
using namespace std;
int n,m,t,x;
priority_queue<int> q;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	q.push(x);
	for(int i=2;i<=n*m;i++)
	{
		cin>>t;
		q.push(t);
	}
	//sort(arr+1,arr+1+n*m,cmp);
	//int l=lower_bound(arr+1,arr+1+n,x)-arr+1;
	int l=0;
	while(1)
	{
		l++;
		if(q.top()==x)
			break;
		else
			q.pop();
	}
	int t=0;
	//cout<<x<<" "<<l<<endl;
//  for(int i=1;i<=n*m;i++)
//		cout<<arr[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				++t;
				if(t==l)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				++t;
				if(t==l)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
    return 0;
}
