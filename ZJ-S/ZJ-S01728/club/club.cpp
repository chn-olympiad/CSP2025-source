#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x,n,T,t1,t2,t3,sum,f1[N],f2[N],f3[N];
struct point
{
	int num1,num2,num3;
}a[N];
int main()
{
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		t1=t2=t3=0;
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].num1>>a[i].num2>>a[i].num3;
			if(a[i].num1>=a[i].num2 && a[i].num1>=a[i].num3) f1[++t1]=a[i].num1-max(a[i].num2,a[i].num3);
			else if(a[i].num2>=a[i].num1 && a[i].num2>=a[i].num3) f2[++t2]=a[i].num2-max(a[i].num1,a[i].num3);
			else f3[++t3]=a[i].num3-max(a[i].num2,a[i].num1);
			sum+=max(a[i].num1,max(a[i].num2,a[i].num3));
		}
		if(t1<=n/2 && t2<=n/2 && t3<=n/2)
		{
			cout<<sum<<"\n";
			continue;
		}
		if(t1>n/2)
		{
			sort(f1+1,f1+1+t1);
			for(int i=1;i<=t1-n/2;i++)
				sum-=f1[i];
		}
		if(t2>n/2)
		{
			sort(f2+1,f2+1+t2);
			for(int i=1;i<=t2-n/2;i++)
				sum-=f2[i];
		}
		if(t3>n/2)
		{
			sort(f3+1,f3+1+t3);
			for(int i=1;i<=t3-n/2;i++)
				sum-=f3[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}

