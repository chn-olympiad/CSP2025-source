#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=110;

int a[N];

inline bool cmp(int a,int b)
{
	return a>b;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x) cout<<ceil((i*1.0)/n)<<" "<<(((int)(ceil((i*1.0)/n))%2==0)? (n-((i%n==0)?n:(i%n))+1):((i%n==0)?n:(i%n)))<<endl;
	return 0;
}
