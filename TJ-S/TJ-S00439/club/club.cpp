#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
//void k(int r[],k)
//{
//	int n=r.rize();
//	if(n<=1) return;
//	int r1[]
//	for(int i=1;i>=n;i++)
//	{
//		
//	}
//}
int main(){
	int t,n,a[100005],sum=0,b[100005];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;	
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[k];
			}
			sort(a+1,a+4);
			sum=sum+a[3];
		sum=0;
		}
		b[i]=sum;
	}
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i=1;i<=t;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
} 
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//10
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//1
//2
//10 9 8
//4 0 0
