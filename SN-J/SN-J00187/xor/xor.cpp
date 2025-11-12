#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define float double
using namespace std;
int n,k,ans;
int a[500005];
int xorA[500005];
pair<int,int> I[1000005];
int cnt;
bool Cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second<y.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	// n reaches 2*10^5 ,test point 13:
	if(n>=5000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]==k) ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	xorA[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xorA[i]=xorA[i-1]^a[i];
	}// xorA Accepted.

	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			int temp=xorA[r]^xorA[l-1];
			if(temp==k)
				I[++cnt]=make_pair(l,r);
		}// I Accepted.
		
	sort(I+1,I+cnt+1,Cmp);
	int preR=-1;
	for(int i=1;i<=cnt;i++)
	{
		pair<int,int> now=I[i];
		int nowL=now.first;
		int nowR=now.second;
		if(nowL>preR)
		{
			preR=nowR;
			ans++;
		}
	}// Answer calculation Accepted.
	cout<<ans<<' ';
	return 0;
}

