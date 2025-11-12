#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,cnt;
int a[10005];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++){
		if (a[i]==x){
			cnt=i;
			break;
		}
	}
	cnt=n*m-cnt+1;
	int l=(cnt-1)/n+1;
	int h=cnt-(l-1)*n;
	if (l%2==0)h=n-h+1;
	cout<<l<<' '<<h<<'\n';
	return 0;
}
/*
4 5
10 1 3 4 5 6 7 8 9 14 11 12 13 2 15 16 17 18 19 20
 */