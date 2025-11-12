#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[101],n,m,c,r,a1,a2;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a1=a[i])
			a2=i;
	}
	c=n-(a2%n);
	if(a2%n!=0)
		r=a2/n+1;
	else
		r=a2/n;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
