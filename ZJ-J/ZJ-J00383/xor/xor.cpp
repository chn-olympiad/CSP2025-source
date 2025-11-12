#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long yihuo(long long a,long long b){
	long long w=0,sum=1;
	while(a!=0||b!=0){
		int s1=a%2,s2=b%2;
		if(s1!=s2){
			w+=sum;
		}
		a/=2;b/=2;
		sum*=2;
	}
	return w;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long cnt=0,ma;
	for(int s=1;s<=n;s++)
	{
	cnt=0;
	for(int i=s;i<=n;i++)
	{
		long long sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=yihuo(sum,a[j]);
			if(sum==m)
			{
				cnt++;
				i=j;
				break;
			}
		}
	}
	ma=max(cnt,ma);
    }
	cout<<ma;
	return 0;
}
