#include <bits/stdc++.h>
//#Shang4Shan3Ruo6Shui4 
using namespace std;
long long a[1005],s[1005][1005],cun,n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cun=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==cun)
		{
			cun=i;
			break;
		}
	}
	long long h=0,l=0;
	if((((cun-1)/n)+1)%2==0) 
	{
		l=(cun-1)/n+1;
		h=n-(cun-1)%n;
	}
	else if((((cun-1)/n)+1)%2==1)
	{
		l=(cun-1)/n+1;
		h=(cun-1)%n+1;
	} 
	cout<<l<<' '<<h;
	/*for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<' ';
	}*/
	return 0;
} 
