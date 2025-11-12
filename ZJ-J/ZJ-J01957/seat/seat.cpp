#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
constexpr int maxn = 13;
int n,m;
int a[maxn*maxn];
int main(){
	IOS;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> a[i];
	int k = a[1],pos = 0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i = 1;i <= n*m;i++)
		if(a[i] == k) pos = i;
	int c = (pos-1)/n+1,r = 0;
	if(c%2) r = pos-(c-1)*n;
	else r = n-(pos-(c-1)*n)+1;
	cout << c << ' ' << r;
	return 0;
}