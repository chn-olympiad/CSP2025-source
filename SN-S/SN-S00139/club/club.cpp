#include <bits/stdc++.h>
using namespace std;
struct S
{
	int a1,a2,a3;
};
int t;
int n,b1,b2,b3;
S a[100005];
int f(int i,int ans)
{
	if(i>n)
	{
		return ans;
	}
	int maxn=ans;
	if(b1<n/2)
	{
		b1+=1;
		maxn=max(maxn,f(i+1,ans+a[i].a1));
		b1-=1;
	}
	if(b2<n/2)
	{
		b2+=1;
		maxn=max(maxn,f(i+1,ans+a[i].a2));
		b2-=1;
	}
	if(b3<n/2)
	{
		b3+=1;
		maxn=max(maxn,f(i+1,ans+a[i].a3));
		b3-=1;
	}
	return maxn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		n=b1=b2=b3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		cout<<f(1,0)<<"\n";
	}
	return 0;
}
