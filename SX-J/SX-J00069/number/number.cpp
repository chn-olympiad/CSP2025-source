#include<bits/stdc++.h>
using namespace std;
long long tong[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
    cin>>a;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			tong[int(a[i])-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(tong[i]!=0)
		{
			tong[i]--;
			cout<<i;
		}
	}
	return 0;
}