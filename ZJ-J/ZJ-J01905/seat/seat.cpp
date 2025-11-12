#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[10005],ai;
bool cmp(ll c,ll b){
	return c>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ai=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ai){
			ll h=(i-1)%n+1;
			ll l=(i-1)/n+1;
			if(l%2==0)h=n-h+1;
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}
