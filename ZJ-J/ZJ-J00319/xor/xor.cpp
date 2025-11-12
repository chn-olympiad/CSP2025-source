#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 	int n,k,sum;
 	cin>>n>>k;
 	for(int i=1;i<=n;i++)
 	{
 		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				sum++;
				continue;
			}
			if(a[i]==a[i+1])
			{
				i++;
				sum++;
			}
		}
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			sum++;
		}
	}
	cout<<sum;
	/*
		I want to stay with you forever,CSP.
		But I'm sorry that I can't achieve it......
		Goodbye CSP.And...
		I'm happy that you are ending now!Hhahaha!
		I'll play games at home!How prefect!!!Yeah!
		However,I must go back to Anji high school to study at afternoon...
		I know my fault,CSP.Please pardon me.
		I really dream to stay with you,believe me.
	*/
	return 0;
}
