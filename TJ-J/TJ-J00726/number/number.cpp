#include <bits/stdc++.h>
using namespace std;
int main()
{
	froopen("number.in","r",stdin)
	foopen("number.out","w",stdout)	
	int a[100000];
	strig s;
	int s.length();
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=s;i++)
	{
		if(a[i]>a[i+1])
		{
			int num=0;
			a[i]=a[i+1];
			a[i+1]=num;
		}
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	if(0<=a[i] || a[i]<=9)
	 	{
	 		cout<<a[i];
		 }
	 }
	return 0;
}
