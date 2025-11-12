#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[105],s;
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h,l;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s){s=i;break;}
	}
	if(((s-1)/n)%2==0)//xia xing lie
	{
		l=(s-1)/n+1;
		h=s%n;
		cout<<l<<" "<<(h==0?n:h);
	}
	else//shang xing lie
	{
		l=(s-1)/n+1;
		h=s%n;
		h=n-(h==0?n:h)+1;
		cout<<l<<" "<<h;
	}
	return 0;
}

