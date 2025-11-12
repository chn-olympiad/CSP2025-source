#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	int li[n];
	for(int i=0;i<n;i++)
	{
		cin>>li[i];
		if(i>0&&li[i]>li[i-1])
		{
			num=li[i];
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
