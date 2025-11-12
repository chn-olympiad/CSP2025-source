#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int R=a[1],ri;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			ri=i;
			break;
		}
	}
	int c=(ri+n-1)/n;
	cout<<c<<" "<<(c%2==1?(ri-1)%n+1:n-(ri-1)%n)<<endl;
	return 0;
}

