//SN-J00922
#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],b[500010];
bool flag=true;
long long sum=0,num=0;
long long min0=1,max1=0;
int main()//only[0,1]
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		min0=min(min0,a[i]);
		max1=max(max1,a[i]);
		b[i]=(b[i-1]^a[i]);//^Ç°×ººÍ 
		if(!flag)
		{
			flag=true;
			b[i]=(b[i]^b[i-1]);//=a[i]
		}
		if(b[i]==k && flag)
		{
			flag=false;
			num++;
		}
	}
	if(min0==1)//tp1 all 1 A
	{
		cout<<n/2;
		return 0;
	}
	if(min0==0 && max1==1)//tp2 1 and 0
	{
//		if(k==1)         //(0^1)=1;(0^0)=1;(1^1)=0;
//		{
//			bool fl[500010]={0};
//			int sum0=0,sumf=0;
//			for(int i=1;i<=n-1;i++)//1 0 0 0 0 0 1 1 0 0 1 1 0 1 1 0 1
//			{
//				if(a[i]==0) sum0++;
//				if(a[i]==0 && a[i-1]==0 && a[i+1]==0 && a[i-2]==1 && a[i+2]==1) sumf++;
//			}
//			cout<<sum0-sumf;
//			return 0;
//		}
		if(k==0)//ok
		{
			bool fl[500010]={0};
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1 && a[i+1]==1)
				{
					if(fl[i] || fl[i+1]) continue;
					sum++;
					fl[i]=1;fl[i+1]=1;
				}
			}
			cout<<sum;
			return 0;
		}
	}
	cout<<num;
	return 0;
}
