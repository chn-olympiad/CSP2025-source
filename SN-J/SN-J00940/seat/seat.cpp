//SN-J00940 ½¯ÓêêØ 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 1005 
using namespace std;
ll n,m,a[maxn],id;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("seat.in","r",stdin); freopen("seat.out","w",stdout);
	cin>>n>>m; for(int i=1;i<=n*m;i++) cin>>a[i];
	id=a[1]; sort(a+1,a+n*m+1,greater<ll>());
	for(int i=1;i<=n*m;i++) if(a[i]==id) {id=i; break;}
	id--; ll x=1,y=1,flag=0;
	while(id--)
	{
		if(!flag) //ÏòÏÂ
		{
			if(x+1<=n) x++;
			else y++,flag=1;
		}
		else
		{
			if(x-1>=1) x--;
			else y++,flag=0;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
