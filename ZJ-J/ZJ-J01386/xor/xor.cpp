/*
test 1-12 AC
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[520000],ans,maxx;
bool flaga=true,flagb=true;
int main()
{
//  考试结束后，必须去除注释! 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]!=1)  flaga=false;
		if(a[i]!=1&&a[i]!=0)  flagb=false;
	}
	/*
	for special A
	if len%2==1 [l,r]=1
	else  [l,r]=0
	*/
	if(flaga)
	{
		if(k==1)  cout<<n;
		else if(k==0)  cout<<n/2;
		else  cout<<0;
		return 0;
	}
	else if(maxx<k)
	{
		cout<<0;
		return 0;
	}
	vector<int> f(n+1,0);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]^a[i];
	}
	int MAXR=2147483647,MINL=2147483647;
	for(int i=min(MINL,n);i>=1;i--)
	{
		for(int j=min(MAXR,n);j>=i;j--)
		{
			if((f[i-1]^f[j])==k)
			{
				ans++;
				MAXR=i-1,MINL=i-1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
