#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
char a,t;
int v[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)
	{
		int x=int(a-'0');
		if(x>=0&&x<=9)v[x]++;
	} 
	bool flag=0;
	for(int i=9;i>=0;i--)
	{
		if(v[i]>0)
		{
			while(v[i]--)cout<<i;
			flag=1;
		}
		if(v[i]==0)
		{
			if(flag==1)
			{
				while(v[i]--)cout<<i;
			}
		}
	}
	if(flag==0)cout<<0;
	return 0;	
} 
