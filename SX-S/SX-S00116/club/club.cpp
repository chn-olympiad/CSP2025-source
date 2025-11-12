#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][13];
long long n,maxx;
void dfs(int k,int sum,int p1,int p2,int p3)
{
	if(k==n+1) {
		maxx=max(maxx,sum*1ll);
		return;
	}
	if(p1>0) dfs(k+1,sum+a[k][1],p1-1,p2,p3);
	if(p2>0) dfs(k+1,sum+a[k][2],p1,p2-1,p3);
	if(p3>0) dfs(k+1,sum+a[k][3],p1,p2,p3-1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--) {
		cin>>n;
		maxx=LLONG_MIN;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,n/2,n/2,n/2);
		cout<<maxx<<'\n';
	}
	return 0;
}
