//陈肖菡 SN-J01123 西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;



int main()
{
	int m,n;
	int c,r;
	cin>>m>>n;
	
	int a[(m*n)+1];
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	int R1;
	R1=a[1];
	sort(a+1,a+(m*n)+1);
	
	int sum=1;
	int b[m*n+1];
	for(int i=m*n;i>0;i--)
	{
		b[i]=a[sum];
		sum+=1;
	}
	
	int R2;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==R1)
		{
			R2=i;
		}
	}
	
	c=R2/n;
	int s2=R2%n;
	
	if(s2<n)
	{
		r=s2;
		cout<<r<<" "<<c+1;
	}
	else if(s2==0&&R2>n)
	{
		cout<<n<<" "<<c+1;
	}
	else if(s2==0&&R2==n)
	{
		cout<<2*n<<" "<<c;
	}
	else
	{
		r=2*n-s2;
		cout<<r<<" "<<c+1;
	}
	
	return 0;
 } 
