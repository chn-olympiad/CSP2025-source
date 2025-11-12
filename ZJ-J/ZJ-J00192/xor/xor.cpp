#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],b[N],ans;
struct node{
	int l,r;
};
vector<node> v;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int x=b[j]^b[i-1];
			if(x==k) v.push_back({i,j});
		}
	}
	int l=0,r=0;
	if(v.size())  
	{
		l=v[0].l,r=v[0].r;
		ans++;
	}
	for(int i=1;i<v.size();i++)
	{
		if(v[i].l==l) continue;
		if(v[i].l>r)  l=v[i].l,r=v[i].r,ans++;
		else if(v[i].r<r) l=v[i].l,r=v[i].r;
	}
	cout<<ans;
	return 0;
}
