#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int n;
	int max;
}a[5005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int b[5005]={};
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		a[i].n=b[i]+a[i-1].n;
		a[i].max=b[i];
	}
	int l=0;
	int cnt=0;
	for(int r=3;r<=n;r++)
	{
		while(a[r].n-a[l].n>a[r].max*2&&r-l>=3)
		{
			cnt++;
			cnt%=998244353;
			r++;
		}
		l++;
	}
	cout<<cnt;
	return 0;
 } 
