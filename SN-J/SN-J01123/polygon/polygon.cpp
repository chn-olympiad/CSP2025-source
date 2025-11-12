//陈肖菡 SN-J01123 西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;
int hanshu(int a,int b[a+1])
{
	int u=0;
	if (a==0) return u;
	
}

int main()
{
	int n,sum=0,x=0;
	cin>>n;
	if(n<=3)
	{
		int a[n+1];
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		
	for(int i=3;i<=n;i++)
	{
		int x=hanshu(n,a[])
	}
	
	if(x>a[n+1]*2)
	{
		sum++;	
	}	
	cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
