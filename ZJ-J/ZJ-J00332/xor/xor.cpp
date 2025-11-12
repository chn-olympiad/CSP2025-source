#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[500005];
int s;
struct node{
	int l,r;
}f[500005];
bool cmp(node x,node y){return x.r<y.r||x.r==y.r&&x.l<y.l;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int x=0,y=i;
		while(y<=n&&a[y]==0)y++;
		for(int j=y;j<=n;j++)
		{
			x=x^a[j];
			if(x==k){f[++m].l=y;f[m].r=j;j=n;}
		}
	}
	sort(f+1,f+m+1,cmp);
	int r=0;
	for(int i=1;i<=m;i++)if(f[i].l>r){r=f[i].r;s++;}
	cout<<s;
	return 0;
}
