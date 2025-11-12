#include<bits/stdc++.h>
using namespace std;
string s;
int a[105];
int n,m,xm,p;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	xm=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xm){
			p=i;
		}
	}
	int x,y;
	if(p%n==0){x=p/n;if(x%2!=0){y=n;}else{y=1;}}
	else {x=p/n+1;if(x%2!=0){y=p%n;}else {y=n+1-p%n;}}
	cout<<x<<" "<<y;
	return 0;
}
