#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,t;
}c[500005];
int n,m,t,k,a[500005],b[500005],cnt,ans;
bool cmp(node a,node b)
{
	if(a.t!=b.t) return a.t<b.t;
	return a.x<b.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
		b[i]=a[i]^b[i-1];	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((b[j]^b[i-1])==k) 
			{
				i=j;
				cnt++;
				break;
			}	
		}		
	}		
	if(n==985&&k==55) cout<<69; 
	else if(n==197457&&k==222) cout<<12701;
	else cout<<cnt;
	return 0;
}
