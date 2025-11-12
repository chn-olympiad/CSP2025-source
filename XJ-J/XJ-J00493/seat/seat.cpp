#include<bits/stdc++.h>
using namespace std;
int a[105];
int m,n,examing,p;

int find(int x)
{
	int l=1,r=m*n;
	while(l<r)
	{
		int mid=(l+r)/2;
		//cout<<mid<<" "<<l<<" "<<r<<" "<<a[mid]<<endl;
		if(a[mid]<=x)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}


int cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	examing=a[1];
	sort(a+1,a+n*m+1,cmp);
/*	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}*/
	p=find(examing);
	//cout<<p<<" ";
	int sumx,sumy;
	if(p%n==0)sumx=p/n;
	else sumx=p/n+1;
	if(p%n==0)
	{
		if(sumx%2==0)sumy=1;
		else sumy=n;
	}
	else
	{
		if(sumx%2==0)sumy=n-p%n+1;
		else sumy=p%n;
	}
	cout<<sumx<<" "<<sumy;
	return 0;
}

