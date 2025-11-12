#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s[500005],last,ans;
struct node{
	long long x,y;
}f[500005];
bool cmp(node x,node y)
{
	if(x.y!=0&&y.y!=0)
	return x.y<y.y;
	if(x.y==0)
	return 0;
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i];
		if(s[i]==k)
		{
			f[i].x=i;
			f[i].y=i;
		}
		for(int j=1;j<i;j++)
		{
			if(f[j].x==0)
			{
				s[j]^=a[i];
				if(s[j]==k)
				{
					f[j].x=j;
					f[j].y=i;
				}
			}
		} 
	}
	sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n&&f[i].x!=0;i++)
	{
		if(f[i].x>last)
		{
			ans++;
			last=f[i].y;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
