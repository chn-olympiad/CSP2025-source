#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string x;
	cin>>x;
	long long a[10]={0};
	for(long long i=0;i<x.size();i++)
	{
		if((x[i]<='9')&&(x[i]>='0')) a[x[i]-'0']++;
	}
	int zz=0;
	for(long long i=9;i>=0;i--)
	{
		while(a[i]!=0)
		{
			zz=zz*10+i;
			a[i]--;
		}
	}
	cout<<zz;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
