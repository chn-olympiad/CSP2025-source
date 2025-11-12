#include <bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n,a[10000];
	int num=0,sum=0;
	cin>>n;
	for(int i=0;i<=100;i++)
	{
		if(n[i]=='0'||n[i]=='1'||n[i]=='2'||n[i]=='3'||n[i]=='4'||n[i]=='5'||n[i]=='6'||n[i]=='7'||n[i]=='8'||n[i]=='9')
		{
			a[i]=n[i];
			num++;
		}
		sum++;
	}
	sort(a,a+sum+1);
	for(int i=sum;i>=0;i--)
	{
		cout<<a[i];
	}
}
