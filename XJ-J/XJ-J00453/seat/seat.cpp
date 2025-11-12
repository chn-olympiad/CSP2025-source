#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[1001];
int v[21];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		v[i]=i;
	}
	int j=n;
	for(int i=n+1;i<=2*n+1;i++)
	{
		v[i]=j;
		j--;
	}
	cin>>b[1];
	x=b[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==b[i])
		{
			x=i;
		}
	}
	if(x<=n)
	{
		cout<<1<<" "<<v[x%(2*n)];
	}
	else
	{
		cout<<x/n+1<<" "<<v[x%(2*n)];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
