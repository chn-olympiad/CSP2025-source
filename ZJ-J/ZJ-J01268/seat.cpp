#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++)
		cin>>a[i];
	int k=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(long long i=1;i<=m*n;i++)
		if(a[i]==k)	{k=i;break;}
	long long t1=ceil(k*1.0/n);	
	long long t2=k-n*(t1-1);
	if(t1%2==0)	
		t2=n-(t2-1);
	cout<<t1<<" "<<t2;
	return 0;
}
