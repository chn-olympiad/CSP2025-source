#include<bits/stdc++.h>
using namespace std;
int a[105];
int x;
bool f(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,f);
	int r=n*m,l=1,mid=0;
	while(r!=l)
	{
		mid=(l+r)/2;
		if(a[mid]==x) 
		{
			int w=mid%n;
			int e=mid/n;
			if(w==0) 
			{
				cout<<e<<" "<<n;
				break;
			}
			else 
			{
				e++;
				cout<<e<<" ";
			}
			if(e%2==0) cout<<m-w+1;
			else cout<<w;
			break;
		}
		else if(a[mid]<x) r=mid-1;
		else if(a[mid]>x) l=mid+1;
	}
	return 0;
}
