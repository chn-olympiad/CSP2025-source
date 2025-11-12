#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,p,ans,dx;
int h,l;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	p=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>p) ans++;
	}
	ans++;
	l=ceil(ans*1.0/n);
	if(l%2==0)
	{
		dx=(l-1)*n+1;
		h=n-(ans-dx);
	}
	else
	{
		dx=l*n;
		h=n-(dx-ans);
	}
	cout<<l<<' '<<h;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
