#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],fa;
long long s(long long _,long long ans)
{
	if(_>n) return ans;
	long long x=a[_];
	if(x==k) return s(_+1,ans+1);
	for(long long i=_+1;i<=n;i++)
	{
		x=x xor a[i];
		if(x==k) return s(i+1,ans+1);
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++) fa=max(fa,s(i,0));
	cout<<fa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
