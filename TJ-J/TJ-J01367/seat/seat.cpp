#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
int tmp;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=a[1]) tmp++;
	}
	int h,l,s;
	l=tmp/n;
	s=tmp%n;
	if(s) l++;
	if(l%2==1)
	{
		h=s;
		if(h==0) h=n;
	}
	else
	{
		h=n-s+1;
		if(h==n+1) h=1;
	}
	cout<<l<<' '<<h;
//	cout<<endl<<s;
	return 0;
}
