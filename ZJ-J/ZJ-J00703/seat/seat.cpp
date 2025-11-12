#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],t,ans,ansx,ansy;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t) ans=i; 
	}
	ansx=(ans+m-1)/m;
	if(ansx%2==0) ansy=m-ans%m+1;
	else ansy=(ans-1)%m+1;
	cout << ansx << " " << ansy;
	
	
	
	
	return 0;
}
