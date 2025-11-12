#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,flag;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int num=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num) flag=i;
	}
	if(flag%n==0) x=flag/n;
	else x=flag/n+1;
	if(x%2!=0) y=flag%n;
	else y=n-(flag%n)+1;
	if(y==0) y=flag;
	cout<<x<<" "<<y<<endl;
	return 0;
}
