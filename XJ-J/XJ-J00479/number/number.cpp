#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int t,i,l,j,num=0;
	string a;
	cin>>a;
	l=a.size();
	for(i=0;i<=l;i++)
	{
		if(char(a[i])<48||char(a[i])>57)
		{
			a[i]=0;
			num++;
		}
	}
	for(i=0;i<=l;i++)
	{
		for(j=0;j<=l;j++)
		{
			if(int(a[j])<int(a[j+1]))
			{
				t=int(a[j]);
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<=l-num;i++)
	{
		cout<<a[i];
	}
	return 0;
}
