#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],s=0;
	int c,r,n;
	cin>>c>>r;
	n=c*r;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		s++;
	}
	int a1,a2;
	a1=s/c+1;
	a2=(s+1)%c;
	if(a2==0)
	a2=c;
	if(a1%2==0)
	a2=c+1-a2;
	cout<<a1<<' '<<a2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
