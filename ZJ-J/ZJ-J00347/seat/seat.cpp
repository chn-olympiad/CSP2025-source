#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N*N];
int n,m;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int res = a[1];
	sort(a+1,a+1+n*m,cmp);
	int x,y;
	x = 1,y = 1;
	if(a[1] == res){
		cout << 1 << " " << 1;
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(x % 2 == 1){
			if(y == n) x ++ ;
			else y ++ ;
		}
		else{
			if(y == 1) x ++ ;
			else y -- ;
		}
		if(a[i] == res){
			cout << x << " " << y;
			return 0;
		}
	}
	return 0;
}
// CSP-S RP++;