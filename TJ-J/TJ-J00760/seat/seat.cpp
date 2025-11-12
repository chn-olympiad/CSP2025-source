#include<iostream>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m; 
	int a[1000]={};
	long long f[200][200]={};
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int k=a[1];
	int t;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			t=i;
		}
	}
	while(t-1>=n)
	{
		t-=n;
		sum++;
	}
	if(sum%2==0)
	{
		cout<<sum+1<<" "<<m-abs(m-t+1)+1;
	}
	else
	{
		cout<<sum+1<<" "<<t+1;
	}
	return 0;
} //#Shang4Shan3Ruo6Shui4 
