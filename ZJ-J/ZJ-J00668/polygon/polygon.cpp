#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],uuz,uus,bc,yu,ans;
void qq(int x,int ma,int zz,int b)
{
	if(x==n+1)
	{
		if(ma*2<zz && b>=3)
		{
			ans++;
			ans%=998244353;
		}
	}
	else{
	qq(x+1,a[x],zz+a[x],b+1);
	qq(x+1,ma,zz,b);
}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		uuz=max(uuz,a[i]);
		uus+=a[i];
	}
	if(uuz==1)
	{
		for(int i=3;i<=n;i++)
		{
			yu=1;
			for(int j=n-i;j<=n;j++)
			{
				yu*=j;
			}
			for(int j=2;j<=i;j++)
			{
				yu/=j;
			}
			if(yu<=0) yu=1;
			ans+=yu;
			ans%=998244353;
		}
	}
	else
	{
		qq(1,0,0,0);
	}
	cout<<ans;
	return 0;
}
