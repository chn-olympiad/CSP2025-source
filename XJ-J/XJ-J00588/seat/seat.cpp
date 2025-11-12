#include<bits/stdc++.h>
using namespace std;
int n,m,a[115],x,cnt=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			int p=cnt%n;
			int w=cnt/n;
			if(p==0)
			{
				cout<<w<<" ";
				if(w%2==0)
				{
					cout<<1;
					break;
				}
				cout<<n;
				break;
			}
			cout<<w+1<<" ";
			if(w%2==0)
			{
				cout<<p;
			}
			else
			{
				cout<<n-p+1;
			}
			break;
		}
		cnt++;
	}
	return 0;
} 
