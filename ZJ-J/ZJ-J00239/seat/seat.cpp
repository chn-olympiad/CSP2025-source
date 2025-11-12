#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[105];
bool cmp(long long x,long long y)
{
	return x>y;
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
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	while(true)
	{
		p++;
		if(a[p]==s) break;
	}
	int l=(p+n-1)/n;
	int h=p%n;
	if(h==0) h=n;
	if(l%2) cout<<l<<" "<<h<<endl;
	else cout<<l<<" "<<n-h+1<<endl;
	return 0;
}
