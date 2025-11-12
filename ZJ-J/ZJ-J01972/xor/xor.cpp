#include<bits/stdc++.h>
using namespace std;
int n,k,B=1,C=1;
struct node{
	int l,r;
}b[500010];
int s[500010],a[500010];
//vector<int> v[266];
bool cmp(node A,node B)
{
	return A.r<B.r;
}
int check(int cnt)
{
//	cout<<endl<<cnt<<endl;
	sort(b+1,b+cnt+1,cmp);
	int last=0,ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(last<b[i].l)
		{
			last=b[i].r;
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor5.in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]&&a[i]!=1)
		{
			B=0;
		}
		if(a[i]>255)
		{
			C=0;
		}
		s[i]=s[i-1]^a[i];
	}
	if(n<=1000)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if((s[i-1]^s[j])==k)
				{
					cnt++;
					b[cnt].l=i;
					b[cnt].r=j;
				}
			}
		}
		cout<<check(cnt);
	}
	else if(B)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
			}
			else if(k==0&&a[i+1]==1)
			{
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
//	else if(C)
//	{
//		int cnt=0,ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			v[s[i]].push_back(i);
//			int len=v[k^s[i]].size(),x=k^s[i];
//			if(len)
//			{
//				cnt++;
//				b[cnt].l=v[x][len-1];
//				b[cnt].r=i;
//				cout<<b[cnt].l<<" "<<b[cnt].r<<endl;
//				v[x].erase(v[x].end()-1);
//			}
//		}
//		cout<<check(cnt);
//	}
	return 0;
}
