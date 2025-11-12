#include<bits/stdc++.h>
using namespace std;
const int N=5e7;
long long int a[N];
struct qj
{
	int sta,en;
}ss[N];
int bj(struct qj a,struct qj b)
{
	if(a.en<b.en)
	{
		return 1;
	}
	else if(a.en==b.en)
	{
		if(a.sta>=b.sta)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	else 
	{
		return 0;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long int s,num=1;
	for(int i=1;i<=n;i++)
	{
		s=a[i];
		if(s==k)
		{
			ss[num].sta=i;
			ss[num].en=i;
			num++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			
			s=s^a[j];
			if(s==k)
			{
				ss[num].sta=i;
				ss[num].en=j;
				num++;
				break;
			}
		}
	}
	sort(ss+1,ss+num,bj);
	int ans=1;
	int end1=ss[1].en;
	for(int i=2;i<=num;i++)
	{
		if(ss[i].sta>end1)
		{
			ans++;
			end1=ss[i].en;
		}
	}
	cout<<ans;
 	return 0;
}