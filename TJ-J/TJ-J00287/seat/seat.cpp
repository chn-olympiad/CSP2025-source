#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
bool cmp(int z1,int z2)
{
	return z1>z2;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int num1=a[1],num2=0;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num1)
		{
			num2=i;
		}
	}
	//cout<<num2;
	int num3=0,num4=0;//储存第一个输出,储存余数 
	if(num2%n==0) num3=num2/n; 
	if(num2%n!=0) num3=num2/n+1; 
	cout<<num3<<" ";
	num4=num2%n;
	if(num3%2==1)
	{
		if(num4==0) cout<<n;
		else cout<<num4;
	}
	if(num3%2==0)
	{
		if(num4==0) cout<<n-num4;
		else cout<<n+1-num4;	
	} 
	return 0;
}
//未通过的数据(已通过)： 9 2 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
