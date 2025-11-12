#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=(1<<20)+10;
vector<int>v[M];
int a[N],f[N];
int find(int t,int x)
{
	int l=0,r=v[t].size()-1,res=-2;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(v[t][mid]<x)
		{
			res=v[t][mid];
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return res;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]^a[i];
		v[f[i]].push_back(i);
	}
	int ans=0;
	for(int i=1,pre=-1;i<=n;i++)
	{
		int t=f[i]^k;
		int pos=find(t,i);
	//	cout<<i<<" "<<pos<<endl;
		if(pos>=pre)
		{
		//	cout<<i<<" "<<pos<<endl;
			pre=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

