//SN-J00384  张溪诺  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int a[5010];
int main()
{
 	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>2*a[3])
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		return 0;
	}
	if(n==4)
	{
		int s=a[1]+a[2]+a[3]+a[4];
		int num=0;
		if((s-a[4])>2*a[3])num++;
		if((s-a[3])>2*a[4])
		{
			num+=3;
		}
		cout<<num;
		return 0;
	}
	else
	{
		cout<<n;
	}
	return 0;
}

