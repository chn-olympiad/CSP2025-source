//陈肖菡 SN-J01123 西安市曲江第一中学

#include<bits/stdc++.h>
using namespace std;



int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	cin>>str;
	int n,m;
	n=str.length();
	m=0;
	int a[n];
	int b[10005];
	
	for(int i=0;i<n;i++)
	{
		a[i]=str[i]; 
		if(a[i]>=48&&a[i]<=57)
		{
			b[m]=a[i]-48;	
			m++;	
		}
	}
	
	sort(b,b+m);
	for(int j=m-1;j>=0;j--)
	{
		cout<<b[j];
	}
	return 0;
 } 
