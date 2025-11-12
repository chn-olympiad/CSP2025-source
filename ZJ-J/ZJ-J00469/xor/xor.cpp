#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int b[N];
int pre[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=n+1;
	int sum=0;
	int mn=-1;
	map<int,int> mp;
	queue<int> q;
	int lpre=0;
	mp[0]=1;
	q.push(0);
	for(int l=1,r=0;l<=n;l++)
	{
		while(r+1<=n)
		{
			if(k>0&&mp.count(sum^k))break;
			if(k==0&&mp.count(sum^k)&&mp[sum^k]>1)break;
			sum^=a[r+1];
			r++;
			mp[sum]++;
			q.push(sum);
		}
		if(l>r)
		{
			r=l;
			sum^=a[r+1];
		}
		if(k>0&&mp.count(sum^k))b[l]=r;
		if(k==0&&mp.count(sum^k)&&mp[sum^k]>1)b[l]=r;
		if(q.size())
		{
			int x=q.front();
			mp[x]--;
			if(mp[x]==0)mp.erase(x);
			q.pop();
		}
	}
	int ans=0;
	int l=1;
	while(l<=n)
	{
		if(b[l]<=n)
		{
			l=b[l]+1;
			ans++;
		}else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
