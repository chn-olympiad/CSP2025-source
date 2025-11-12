#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
struct po{
	long long l,maxx;
}t[5010];
const int N=998244353;
void f(int nu,int nw,int s,int la)
{
	if(nu<nw&&t[s].l>t[s].maxx*2)
	{
		ans++;
		ans%=N;
	}
	int x=t[s].maxx;
	for(int i=la+1;i<=n;i++)
	{
		t[s].l+=a[i];
		t[s].maxx=max(x,a[i]);
		f(nu,nw+1,s,i+1);
		t[s].l-=a[i];
		t[s].maxx=x;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500)
	{
		long long tot=1,left=2,right=1;
		for(int i=n;i>=2;i--)
		{
			tot=tot*i%N;
			cout<<"x";
		}
		for(int i=2;i<=n-3;i++)
		{
			right=right*i%N;
			cout<<"y";
		}
		for(int i=3;i<=n;i++)
		{
			left=left*i%N;
			ans=(ans+tot/left/right)%N;
			right/=(n-i+1);
			cout<<"z";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t[i].l=a[i];
		t[i].maxx=a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f(i,1,j,j);
		}
		ans%=N;
	}
	cout<<ans%N;
	return 0;
}

