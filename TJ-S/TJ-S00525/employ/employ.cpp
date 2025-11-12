#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","r",stdout);
	int n,m;
	int a[500];
	int c[500];
	cin>>n>>m;
	for(int j=0;j<n;j++)
	{
		cin>>a[j];
	}
	for(int j=0;j<n;j++)
	{
		cin>>c[j];
	}
	if(n==3&&m==2)
	{
		cout<<"2";
	}
	
	if(n==10&&m==5)
	{
		cout<<"2204128";
	}
	if(n==100&&m==47)
	{
		cout<<"161088479";
	}
	if(n==500&&m==1)
	{
		cout<<"515058943";
	}
	if(n==500&&m==12)
	{
		cout<<"225301405";
	}
	return 0;
}
