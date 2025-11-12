#include<bits/stdc++.h>
using namespace std;
int a[111];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],id=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x) id=i; 
	}
	int l=id/n,t=id%n;
	if(t!=0) l++;
	else t=n;
	if(l%2==1)
	{
		cout<<l<<" "<<t;
	}
	if(l%2==0)
	{
		cout<<l<<" "<<n-t+1;
	}
	fclose(stdin);
	fclose(stdout);
}
