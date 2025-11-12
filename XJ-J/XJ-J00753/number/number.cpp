#include<bits/stdc++.h>
using namespace std;
int s,n[1000005],w=1;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ss=s;
	while(s!=1&&s!=2&&s!=3&&s!=4&&s!=5&&s!=6&&s!=7&&s!=8&&s!=9)
	{
		s/=10;
		w++; 
		
	}
	
	
	for(int i=w;i>=1;i--)
	{
		n[i]=ss%10;
		ss/=10;
	}
	for(int j=1;j<=10;j++)
	{
		for(int i=1;i<=w;i++)
	{
		if(n[i+1]>n[i])
		{
			int t=n[i];
			n[i]=n[i+1];
			n[i+1]=t;
		}
	}
	} 
	
	
	for(int i=1;i<=w;i++)
	{
		cout<<n[i];
	}
	
	return 0;
 } 
