#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int t,n,num,cnt1,cnt2,cnt3,a[100005],b[100005],c[100005];
bool flag1=1;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		num=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)
			{
				flag1=false;
			}
			if(a[i]>b[i]&&a[i]>c[i])
			{
				if(cnt1<n/2)
				{
					cnt1++;
					num+=a[i];
				}
				else if(b[i]>c[i])
				{
					cnt2++;
					num+=b[i];
				}
				else
				{
					cnt3++;
					num+=c[i];
				}
			}
			if(c[i]>b[i]&&c[i]>a[i])
			{
				if(cnt3<n/2)
				{
					cnt3++;
					num+=c[i];
				}
				else if(a[i]>b[i])
				{
					cnt1++;
					num+=a[i];
				}
				else
				{
					cnt2++;
					num+=b[i];
				}
			}
			if(b[i]>a[i]&&b[i]>c[i])
			{
				if(cnt2<n/2)
				{
					cnt2++;
					num+=b[i];
				}
				else if(a[i]>c[i])
				{
					cnt1++;
					num+=a[i];
				}
				else
				{
					cnt3++;
					num+=c[i];
				}
			}
		}
		if(flag1)
		{
			int num2=0;
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--)
			{
				num2+=a[i];
			}
			cout<<num2<<endl;
			continue;
		}
		cout<<num<<endl;
	}
	return 0;
}