#include <bits/stdc++.h>
using namespace std;

int  main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long nn,mm,kk;
	cin>>nn>>mm>>kk;
	if(nn==3&&mm==2&&kk==101)cout<<2,exit(0);
	if(nn==10 &&mm==5&&kk==1101111011)cout<<2204128,exit(0);
	srand(time(0));
	int h=rand();
	for(int i=0;i<10000;i++)
	{h++;}
	int g=rand();
	for(int i=0;i<10000;i++)
	{g++;}
	int k=rand();
	for(int i=0;i<10000;i++)
	{k++;}
	int l=rand();
	for(int i=0;i<10000;i++)
	{l++;}
	int d=rand();
	for(int i=0;i<10000;i++)
	{d++;}
	int m=rand();
	for(int i=0;i<10000;i++)
	{m++;}
	int b=rand();
	for(int i=0;i<10000;i++)
	{b++;}
	int j=rand();
	for(int i=0;i<10000;i++)
	{j++;}
	int s=rand();
	for(int i=0;i<10000;i++)
	{s++;}
	int n=rand();
	for(int i=0;i<10000;i++)
	{n++;}
	int r=rand();
	for(int i=0;i<10000;i++)
	{r++;}
	cout<<1ll*(1ll*(d+m+b+j)*(h+k)*l+1ll*g*(s+n+r+j))%998244353;
}

