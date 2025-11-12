#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=998224353;
int n,a[N];
bool cmp(int a,int b) {
	return a>b;
}

int c(int n,int m)
{
	unsigned long long t1=1,t2=1;
	if(n-m<m) m=n-m;
	if(n==m) return 1;
	for(int i=0;i<m;i++) 
	{
		t1*=n-i;
	}
	for(int i=1;i<=m;i++) 
	{
		t2*=i;
	}
	return (t1/t2)%M;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	
	if(a[1]==1) 
	{
		int he=0;
		for(int i=3;i<=n;i++)
		{
			he+=c(n,i)%M;
			he%=M;
		}
		cout<<he%M;
	}
	else if(n==3)
	{
		if(a[1]<a[2]+a[3]) cout<<1;
		else cout<<0;
	}
	return 0; 
}
