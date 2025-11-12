#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,T;
struct stu{
	int a1,a2,a3;
}person[M];
struct stu1{
	int data;
	bool flag;
}f[M];
int dp[M];
bool flag[M];
int cmp(stu1 a,stu1 b)
{
	return a.data<b.data;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(;T;T--)
	{
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=f[i].data=f[i].flag=0;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>person[i].a1>>person[i].a2>>person[i].a3;
			int maxn=max(person[i].a1,max(person[i].a2,person[i].a3));
			if(person[i].a1==maxn) cnt1++;
			if(person[i].a2==maxn) cnt2++;
			if(person[i].a3==maxn) cnt3++;
		}
		int maxcnt=max(cnt1,max(cnt2,cnt3));
		for(int i=1;i<=n;i++)
		{
			int max1=max(person[i].a1,max(person[i].a2,person[i].a3)),max2;
			if(person[i].a1==max1)
			{
				if(person[i].a2>person[i].a3) max2=person[i].a2;
				else max2=person[i].a3;
			}
			if(person[i].a2==max1)
			{
				if(person[i].a1>person[i].a3) max2=person[i].a1;
				else max2=person[i].a3;
			}
			if(person[i].a3==max1)
			{
				if(person[i].a2>person[i].a1) max2=person[i].a2;
				else max2=person[i].a1;
			}
			f[i].data=max1-max2;
			if(person[i].a1==max1)
			{
				if(num1<n/2)
				{
					num1++;
					if(maxcnt==cnt1) f[i].flag=1;
					dp[i]=dp[i-1]+max1;
					continue;
				}
			}
			if(person[i].a2==max1)
			{
				if(num2<n/2)
				{
					num2++;
					if(maxcnt==cnt2) f[i].flag=1;
					dp[i]=dp[i-1]+max1;
					continue;
				}
			}
			if(person[i].a3==max1)
			{
				if(num3<n/2)
				{
					num3++;
					if(maxcnt==cnt3) f[i].flag=1;
					dp[i]=dp[i-1]+max1;
					continue;
				}
			}
			sort(f+1,f+i,cmp);
			bool fl=0;
			for(int j=1;j<=n;j++)
			{
				if(f[i].data>=f[j].data&&f[j].flag)
				{
					dp[i]=dp[i-1]-f[j].data+max1;
					f[j].flag=0;
					fl=1;
					f[i].flag=1;
					break;
				}
			}
			if(!fl) dp[i]=dp[i-1]+max2;
		}
		cout<<dp[n]<<"\n";
	}
	return 0;
}
