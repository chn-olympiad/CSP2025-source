#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct cy
{
	int a1,a2,a3;
};
const int N=1e5;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t,ji=0,ans[1000];
	cin>>t;
	while(1)
	{
		if(t==0)
			break;
		t--;
		int n,z=0,a[N][N],b[N][N],x1[N],x2[N],x3[N],xx1=0,xx2=0,xx3=0,bx[N];
		cin >> n;
		cy s[N];
		int zd=n/2;
		for(int i=0;i<n;i++)
		{
			cin >>s[i].a1>>s[i].a2>>s[i].a3;
			a[i][0]=s[i].a1;
			a[i][1]=s[i].a2;
			a[i][2]=s[i].a3;
		}
		for(int i=0;i<n;i++)
		{
			x1[i]=a[i][0];
		}
		for(int i=0;i<n;i++)
		{
			x2[i]=a[i][1];
		}
		for(int i=0;i<n;i++)
		{
			x3[i]=a[i][2];
		}
		int bxx=0;
		sort(x1,x1+n,greater<int>());
		sort(x2,x3+n,greater<int>());
		sort(x3,x3+n,greater<int>());
		for(int i=0;i<zd;i++)
		{
			bx[bxx]=x1[i];
			bxx++;
		}
		for(int i=0;i<zd;i++)
		{
			bx[bxx]=x2[i];
			bxx++;
		}
		for(int i=0;i<zd;i++)
		{
			bx[bxx]=x3[i];
			bxx++;
		}
		bxx-=1;
		sort(bx,bx+bxx);
		for(int i=0;i<n;i++)
			z+=bx[i];
		ans[ji]=z;
		ji++;
	}
	for(int i=0;i<ji;i++)
		cout<<ans[i]<<endl;
	return 0;	
} 
