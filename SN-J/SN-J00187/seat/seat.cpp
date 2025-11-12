#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define float double
using namespace std;
int n,m,T;
int a[105];
bool Cmp(int x,int y)
{
	return x>y;
}
pair<int,int> Ans(int x)
{
	int L=(x%n==0)?x/n:x/n+1;
	int H=(x%n==0)?n:x%n;
	if(L%2==0)
		H=n-H+1;
	return make_pair(L,H);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	T=a[1];
	sort(a+1,a+n*m+1,Cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
		if(a[i]==T)
		{
			pos=i;
			break;
		}
	pair<int,int> ans=Ans(pos);
	cout<<ans.first<<' '<<ans.second<<'\n';
	return 0;
}

