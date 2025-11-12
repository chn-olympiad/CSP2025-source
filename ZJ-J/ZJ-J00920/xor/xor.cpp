#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[500005],sum=0,l=0,p;
struct stu{
	int x,y;
}w[5000005];
bool cmp(stu p,stu q)
{
	return p.y<q.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	cin>>n>>k;
	freopen("xor.out","w",stdout);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=(f[i-1]^a[i]);
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((f[i]^f[j])==k)
			{
				l++;
				w[l].x=i+1;
				w[l].y=j;
			}
		}
	}
	sort(w+1,w+l+1,cmp);
	for(int i=1;i<=l;i++)
	{
		if(i==1)
		{
			p=w[i].y;
			sum++;
		}
		else
		{
			if(w[i].x>p)
			{
				sum++;
				p=w[i].y;
			}
		}
	}	
	cout<<sum;			
	fclose(stdin);
	fclose(stdout);
	return 0;
}