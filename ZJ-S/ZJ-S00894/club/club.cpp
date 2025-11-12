#include<bits/stdc++.h>
using namespace std;
long long t,n,maxn,b[5],a[100100][5],c[100100];
bool p[100100][5];
void dfs(long long k,long long s)
{
	if(k>n) return;
	for(int i=1;i<=3;i++)
	  if(b[i]<n/2&&p[k][i]==false)
	  {
	  	s+=a[k][i];
	  	maxn=max(maxn,s);
	  	p[k][i]=true;
	  	b[i]++;
	  	dfs(k+1,s);
	  	s-=a[k][i];
	  	b[i]--;
	  	p[k][i]=false;
	  }
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		maxn=0;
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(n==2)
		{
			long long s1,s2,s3,s4,s5,s6;
			s1=a[1][1]+a[2][2];
			s2=a[1][1]+a[2][3];
			s3=a[1][2]+a[2][1];
			s4=a[1][2]+a[2][3];
			s5=a[1][3]+a[2][1];
			s6=a[1][3]+a[2][2];
			cout<<max(max(max(max(max(s1,s2),s3),s4),s5),s6);
			return 0;
		}
		if(n<=200)
		{
			dfs(1,0);
			cout<<maxn<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++) c[i]=a[i][3];
			sort(c+1,c+n+1);
			for(int i=n;i>=n/2;i--) maxn+=c[i];
			cout<<maxn<<endl;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
