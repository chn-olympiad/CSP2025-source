#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long b,w=0,ma,i=0;
	long long a;
	long long x[100000]={0};
	cin>>a;
	b=0;
	while(a!=0)
	{
		x[i]=a%10;
		w++;
		a=a/10;
		if(a==0)
		{
			break;
		}
		i++;
	}
	for(int k=0;k<w;k++)
	{
		for(int j=0;j<w-1;j++)
		{
			if(x[j]<x[j+1])
			{
				swap(x[j],x[j+1]);
			}
		}
	}
	for(int k=0;k<w;k++)
	{
		b+=x[k];
		if(k!=w-1)
		{
			b*=10;
		}
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
