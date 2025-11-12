#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long n,a[100001],h=1,ans,cnt;
long long kt[100001],w[100001];
int C(int x,int y)
{
	long long qwq1=1,qwq2=1;
	for(int j=y;j>=y-x+1;j--) qwq1=qwq1*j;
	for(int j=x;j>=1;j--) qwq2=qwq2*j;
	return qwq1/qwq2%N;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) h=0;
	}
	sort(a+1,a+1+n);
	if(h)
	{
		for(int i=3;i<=n;i++)
		{
			int k=i;
			if(n/2<k) k=n-k;
			ans=(ans+C(k,n))%N;
		}
			
		cout<<ans;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		int qwq=1;
		memset(w,0,sizeof(w));
		memset(kt,0,sizeof(kt));
		for(int j=1;j<=i;j++) 
		{
			w[j]=j;
			kt[j]=j;
		}
		while(qwq)
		{
			ans=0;
			for(int j=1;j<=i;j++) ans+=a[w[j]];
			if(ans>2*a[w[i]]) cnt=(cnt+1)%N;
			w[i]++;
			int z=i;
			while(w[z]>n+z-i&&z>=1)
			{
				
				if(z==1&&w[z]>=n+z-i) 
				{
					qwq=0;
					break;
				}
				w[z]=kt[z]+1;
				if(w[z]>n+z-i) w[z]=n+z-i;
				w[z-1]++;
				kt[z]++;
				z--;
			} 
		}
	}
	cout<<cnt<<endl;
	return 0;
}