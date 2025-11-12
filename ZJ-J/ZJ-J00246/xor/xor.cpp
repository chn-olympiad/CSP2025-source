#include<bits/stdc++.h>
using namespace std;
int n,s1[50005],s2[50005],s3[50005];
long long k,a[500005],b[500005],cnt,m=0;
long long ejz(long long x,long long y)
{
	if (x==y) return x;
	int j1=1;
	if (x!=0)
	{
		while(x!=1)
		{
			s1[j1]=x%2;
			x/=2;
			j1++;
		}
		s1[j1]=x;
	}
	int j2=1;
	if (y!=0)
	{
		while(y!=1)
		{
			s2[j2]=y%2;
			y/=2;
			j2++;
		}
		s2[j2]=y;
	}
	for(int i=1;i<=max(j1,j2);i++)
	{
		if (s1[i]!=s2[i]) s3[i]=1;
		else s3[i]=0;
	}
	long long t=0;
	for(int i=1;i<=max(j1,j2);i++) t+=s3[i]*pow(2,i-1);
	return t;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if (k==0)
	{
		for(int i=1;i<=n;i++)
			if (a[i]==0) cnt++;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memcpy(b,a,sizeof(a));
		long long m=0;
		for(int j=i;j<n;j++)
		{
			int q1=b[j],q2=b[j+1];
			m=ejz(q1,q2);
			b[j+1]=m;
			if (m==k) cnt++;
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		long long h=ejz(a[i],a[i]);
		if (h==k) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}