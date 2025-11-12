#include<bits/stdc++.h>
using namespace std;
int _,a[100001],b[100001],c[100001],n,maxx=-1;
bool A=1;
void dfs(int s,int aa,int bb,int cc,int sum)
{
	if(s>n)
	{
		maxx=max(maxx,sum);
		return ;
	}
	if(aa>=1) dfs(s+1,aa-1,bb,cc,sum+a[s]);
	if(bb>=1) dfs(s+1,aa,bb-1,cc,sum+b[s]);
	if(cc>=1) dfs(s+1,aa,bb,cc-1,sum+c[s]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--)
	{
		maxx=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0) A=0;
		}
		if(!A) dfs(1,n/2,n/2,n/2,0);
		else if(A)
		{
			maxx=0;
			sort(a+1,a+n+1,greater<int>());
			for(int i=1;i<=n/2;i++)
			{
				maxx+=a[i];
			}
		}
		
		cout<<maxx<<"\n";
	}
	return 0;
}

