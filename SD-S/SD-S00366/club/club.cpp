#include<bits/stdc++.h>
using namespace std;
struct def{
	long long a;
	long long b;
	long long c;
}sat[100005];
long long ans[100005];
int n,p=1;
int k;
void f(int i,int a,int b,int c,long long num)
{
	if (i>n) 
	{
		ans[p]=num;
		p++;
	}
	else
	{
		if (a<k) 
		{
			int u = num+sat[i].a;
			f(i+1,a+1,b,c,u);
		}
		if (b<k) 
		{
			int u = num+sat[i].b;
			f(i+1,a,b+1,c,u);
		}
		if (c<k) 
		{
			int u = num+sat[i].c;
			f(i+1,a,b,c+1,u);
		}
	}
}
bool cmp1(int a,int b)
{
	return a>b;
}
bool cmp2(def a,def b)
{
	return a.a>b.a;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		p = 0;
		k = n/2;
		for (int i = 1 ; i <= n ; i++) cin>>sat[i].a>>sat[i].b>>sat[i].c;
		if (n>=99999)
		{
			sort(sat+1,sat+n+1,cmp2);
			long long num = 0;
			for (int i = 1 ; i <= k ; i++)
			{
				num+=sat[i].a;
			}
			cout<<num;
		}
		else
		{
			f(1,0,0,0,0);
			sort(ans+1,ans+p+1,cmp1);
			cout<<ans[1]<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
