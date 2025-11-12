//西安高新第二初级中学  姜璟烁  SN-J00237 
#include<bits/stdc++.h>
using namespace std;
const int maxn=12;
int zhuowei[maxn][maxn];
int shuru[1005];
int m,n,c,r,cnt,xiaor;
bool cmp(int a,int b)
{
	return a>b;
}
int findd(int a[],int b)
{
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==b)
		{
			return i;
		}
	}
}
bool isdouble(int x)
{
	if(x%2==0)
	{
		return true;
	}
	else 
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=m*n;
	for(int i=1;i<=cnt;i++)
	{
		cin>>shuru[i]; 
	}
	xiaor=shuru[1];
	sort(shuru+1,shuru+cnt+1,cmp);
	
	int ans=findd(shuru,xiaor);
	int k;
	if(ans%n==0)
	{
		k=ans/n;
	}
	else
	{
		k=ans/n+1; 
	}
	cout<<k<<" ";
	
	int k1=ans%n;
	if(isdouble(k)==1)
	{
		cout<<n-k1+1;
	}
	else if(isdouble(k)==0)
	{
		if(k1==0)
		{
			cout<<n;
		}
		else
		{
			cout<<k1;
		}
	}


	return 0;
}
