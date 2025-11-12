#include<bits/stdc++.h>
using namespace std;
struct menber{
	long long a1,a2,a3,cha12,cha13,cha23,cha21,cha31,cha32;
}a[100005],b1[100005],b2[100005],b3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++)
	{
		long long n,b1s=0,b2s=0,b3s=0;
		long long s=0,k;
		scanf("%lld",&n);
		k=n/2;
		for(long long j=1;j<=n;j++)
		{
			scanf("%lld",&a[j].a1);
			scanf("%lld",&a[j].a2);
			scanf("%lld",&a[j].a3);
			a[j].cha12=a[j].a1-a[j].a2;
			a[j].cha13=a[j].a1-a[j].a3;
			a[j].cha23=a[j].a2-a[j].a3;
			a[j].cha21=a[j].a2-a[j].a1;
			a[j].cha31=a[j].a3-a[j].a1;
			a[j].cha32=a[j].a3-a[j].a2;
			if(max(a[j].a1,max(a[j].a2,a[j].a3))==a[j].a1)
			{
				s+=a[j].a1;
				b1s++;
				b1[j].cha12=a[j].cha12;
				b1[j].cha13=a[j].cha13;
			}
			else
			{
				if(max(a[j].a2,a[j].a3)==a[j].a2)
				{
					s+=a[j].a2;
					b2s++;
					b2[j].cha23=a[j].cha23;
					b2[j].cha21=a[j].cha21;
				}
				else
				{
					s+=a[j].a3;
					b3s++;
					b3[j].cha31=a[j].cha31;
					b3[j].cha32=a[j].cha32;
				}
			}
		}
		long long b11=b1s;
		while(b1s>k)
		{
			long long min1=999999,m=0;
			for(long long j=1;j<=b11;j++)
			{
				if(j==m)
					continue;	
				min1=min(min1,min(b1[j].cha12,b1[j].cha13));
				if(b1[j].cha12<min1||b1[j].cha13<min1)
					m=j;
			}
			s+=min1;
			b1s--;
			b1[m].cha13=999999;
			b1[m].cha12=999999;
		}
		long long b22=b2s;
		while(b2s>k)
		{
			long long min1=999999,m=0;
			for(long long j=1;j<=b22;j++)
			{
				if(j==m)
					continue;
				min1=min(min1,min(b2[j].cha21,b2[j].cha23));
				if(b2[j].cha21<min1||b2[j].cha23<min1)
					m=j;
			}
			s+=min1;
			b2s--;
			b2[m].cha21=999999;
			b2[m].cha23=999999;
		}
		long long b33=b3s;
		while(b3s>k)
		{
			long long min1=999999,m;
			for(long long j=1;j<=b33;j++)
			{
				min1=min(min1,min(b3[j].cha32,b3[j].cha31));
				if(b3[j].cha31<min1||b3[j].cha32<min1)
					m=j;
		 	}
			s+=min1;
			b3s--;
			b3[m].cha32=999999;
			b3[m].cha31=999999;
		}
		cout<<s<<endl;
	}
	return 0;
}