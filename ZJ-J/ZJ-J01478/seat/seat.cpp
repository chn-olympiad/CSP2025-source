#include<bits/stdc++.h>
using namespace std;
int s[105];
bool sx(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,x,y;
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	scanf("%d",&s[i]);
	r=s[0];
	sort(s,s+m*n,sx);
	for(int i=0;i<m*n;i++)
	if(s[i]==r)
	{
		r=i+1;
		break;
	}
	x=r/n;
	if(r%n!=0)
	x++;
	if(x%2)
	y=r-(x-1)*n;
	else
	y=x*n-r+1;
	cout<<x<<' '<<y;
	return 0;
}
