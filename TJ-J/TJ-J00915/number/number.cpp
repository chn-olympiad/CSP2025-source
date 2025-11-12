#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[1001000],c,cnt,cnt1,t,sum,p;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if((s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90))
		{
			cnt++;
		}
		else
		{
			s[i]-=48;
			a[i]=s[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]>a[j])
			{
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
	}
	cnt1=n-cnt+1;
	t=pow(10,cnt1);
	for(int i=0;i<n;i++)
	{
		sum+=a[i]*t;
		t/=10;
	}
	p=pow(10,cnt);
	sum/=100;
	cout<<sum<<endl;
	return 0;
}
