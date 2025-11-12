#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[10]={0,0,0,0,0,0,0,0,0,0},s,n=0;
	cin>>s;
	for(int i=1;i<=8;i++)
	{
		if(s/10==0)
		{
			n+=1;
			a[s%10]+=1;
			s/=10;
			break;
		}
		else
		{
			n+=1;
			a[s%10]+=1;
			s/=10;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=9;j>=0;j--)
		{
			if(a[j]!=0)
			{
				cout<<j;
				a[j]--;
				break;
			}
		}
	}
	return 0;
}
