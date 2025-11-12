#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[2005],x,id;
bool cmp(int p1,int p2){
	return p1 > p2;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	x = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(x == a[i]){
			id = i;
			break;
		}
	}
	int h = id/(2*n),h1 = id%(2*n);
	if(h1 > n)
		cout << 2*h+2 << ' ' << 2*n - h1 + 1 << '\n';
	else
		cout << 2*h+1 << ' ' << h1 << '\n';
	return 0;
}
/* 
	               ◢◤
	           ◢▆◤
	   ◢   ◢▇◤
	 ◢▇▆▇◤
	 ◥▇▇◤
     Just Do It
   尽管我无法证明他的对错，
   	   但我坚信他是对的
*/
