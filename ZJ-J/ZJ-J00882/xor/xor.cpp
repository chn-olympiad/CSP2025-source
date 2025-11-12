#include<bits/stdc++.h>
using namespace std;
struct fe
{
	int st,en;
}a[10101];
bool cmp(fe x,fe y)
{
	if(x.st==y.st)return (x.en-x.st)<(y.en-y.st);
	return x.st<y.st;
}
int f[10101],ko[10101];
int h[501010],su[501010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>h[i];
	su[1]=h[1];
	for(int i=2;i<=n;i++)su[i]=su[i-1]^h[i];
//	for(int i=1;i<=n;i++)cout<<su[i]<<' ';
	int o=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if((su[r]^su[l-1])==k)
			{
				o++;
				a[o].st=l;
				a[o].en=r;
//				cout<<l<<' '<<r<<endl;
			}
		}
	}
	sort(a+1,a+1+o,cmp);
	f[1]=1;
	for(int i=1;i<=o;i++)
	{
		int now=i;
		memset(ko,0,sizeof ko);
		ko[i]=1;
		for(int j=i+1;j<=o;j++)
		{
			if(ko[j]<ko[j-1])
			{
				ko[j]=ko[j-1];
			}
			if(a[now].en<a[j].st)ko[j]=ko[j]+1,now=j;
		}
		for(int j=1;j<=o;j++)f[j]=max(f[j],ko[j]);
	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	cout<<*max_element(f+1,f+1+o);
	return 0;
}//10pts
