#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],b[500005],vis[500005];
bool f=1;
struct node
{
	int l,r;
	bool operator<(node b)const{
		if(r-l!=b.r-b.l)return r-l<b.r-b.l;
		return l>b.l;
	}
};
vector<node>v;
bool ch(node a)
{
	for(int i=a.l;i<=a.r;i++)
	{
		if(vis[i])return 0;
	}
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
		if(i==1)b[i]=a[i];
		else b[i]=b[i-1]^a[i];
		if(a[i]!=0&&a[i]!=1)f=0;
	}
	if(f)
	{
		int ans=0;
	//	cout<<"23423432432"<<endl;
		if(k==1)
		{
			for(int i=1;i<=n;i++)ans+=a[i];
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==k)ans++;
				if(a[i]==a[i+1]&&a[i]!=k)ans++,i++;
			}
		}
		
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==k)v.push_back({1,i});
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if((b[j]^b[i-1])==k)
				{	
					v.push_back({i,j});
				}
			}
		}
		sort(v.begin(),v.end());
		int ans=0;
		for(node it:v)	
		{
			
			if(ch(it))
			{
				for(int i=it.l;i<=it.r;i++)vis[i]=1;
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}