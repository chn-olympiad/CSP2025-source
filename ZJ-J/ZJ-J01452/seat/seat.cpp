#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
int n,m,k;
struct A{
	int x,y;
	bool operator < (const A & b) const{
		return x > b.x;
	}
}a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	k = n * m;
	for (int i = 1;i <= k;++ i){
		cin>>a[i].x;
		a[i].y = i == 1;
	}
	sort(a+1,a+k+1);
	for (int i = 1,j = 1,l = 1;;++ l){
		if (a[l].y){
			cout<<j<<' '<<i;
			return 0;
		}
		if (j & 1){
			if (i != n){
				i ++;
			}
			else {
				j ++;
			}
		}
		else {
			if (i != 1){
				i --;
			}
			else {
				j ++;
			}
		}
	}
	return 0;
}