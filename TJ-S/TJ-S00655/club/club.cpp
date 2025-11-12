//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*int abc(int x,int y,int z)
{
	int k=max(x,y);
	int m=max(k,m);
	return m;
}*/
int main ()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[1000];
	int a[10000]={0},b[10000]={0},c[10000]={0},suw[10000]={0};
	for(int i=0;i<t;i++)
	{
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			cin >>a[j]>>b[j]>>c[j];
			suw[i]+=max(max(a[j],b[j]),c[j]);
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<suw[i]<<endl;
	}
/*	int suw[10000]={0};
	for(int i=0;i<t;i++)
	{
		suw[i]=0;
		for(int j=0;j<n[i];j++)
		{
			//cout<<a[j]<<" "<<b[j]<<' '<<c[j]<<endl;
			//sum[j]=0;
			sum[j]=abc(a[j],b[j],c[j]);
			cout<<sum[j]<<endl;
			//cout<<suw[i]<<endl;
		}
		cout<<suw[i]<<endl;
	}
*/
	return 0;	
}
//#include<iostream>
/*
#include<bits/stdc++.h>
using namespace std;
int main ()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n[10000];
	int a[10000],b[10000],c[10000],sum[10000];
	int suw[10000]={0};
	for(int i=0;i<t;i++)
	{
		cin >>n[i];
		for(int j=0;j<n[i];j++)
		{
			cin >>a[j]>>b[j]>>c[j];
			int m=max(a[j],b[j]);
			sum[j]=max(m,c[j]);
			sum[i]+=sum[j];
		}
		cout<<sum[i]<<endl;
	}
	

	return 0;	
}*/
