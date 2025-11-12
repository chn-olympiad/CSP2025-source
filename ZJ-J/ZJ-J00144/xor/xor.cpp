#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
long long sum[MAXN];
int n,k,a[MAXN],answ[MAXN],mp[MAXN];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		answ[i]=answ[i-1];
		sum[i]=sum[i-1]^a[i];
		if(sum[i]==k)
		{
			answ[i]=max(answ[i-1],1);
		}
		long long c=sum[i]^k;
		if(!mp[c])
		{
			mp[sum[i]]=i;
			continue;
		}
		answ[i]=max(answ[i],answ[mp[c]]+1);
		mp[sum[i]]=i;
	}
	cout<<answ[n];
	return 0;
}