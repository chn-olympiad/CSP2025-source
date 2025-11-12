#include<bits/stdc++.h>
using namespace std;
long long a[5111],s,n;
void dfs(long long x,long long y,long long z,long long p)
{
	if(y>2*z&&p>=3) 
	{
		int e=1;
		while(x)
		{
			x--;
			e*=2;
		}
		s+=e;
		s%=998244353;
//		cout<<z<<" "<<p<<endl;
	}	
	if(x<1) return;
	dfs(x-1,y+a[x],max(a[x],z),p+1);
	dfs(x-1,y,z,p);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(n,0,0,0);
	cout<<s%998244353;
	return 0;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/