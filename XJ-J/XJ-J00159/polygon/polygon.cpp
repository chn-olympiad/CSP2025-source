#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int x,int y)
{
	if(x>y) return true;
	return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,n,s=0;
	cin>>n;
	if(n<3)
	{
		cout<<"0"; return 0;
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+i+1,cmp);
	if(n==3&&a[3]+a[2]>a[1])
	{
		cout<<"1";
		return 0;
	} else
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n-2;j++)
			{
				if(a[j+1]+a[j]>a[i]) s++;
			} //cout<<s<<endl;
			for(j=i+1;j<=n-3;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-4;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-5;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[j+4]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-6;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-7;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-8;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6]+a[j+7]+a[i]>a[i]*2) s++;
			}
			for(j=i+1;j<=n-9;j++)
			{
				if(a[j]+a[j+1]+a[j+2]+a[j+3]+a[j+4]+a[j+5]+a[j+6]+a[j+7]+a[j+8]+a[i]>a[i]*2) s++;
			}
		}
		
	}
	cout<<s; 
	return 0;
 } 
