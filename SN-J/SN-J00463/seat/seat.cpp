#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
struct A{
	int cj,bh;
}a[110];
bool cmp(A x,A y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].bh=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int xk=0,yk=1;
	for(int i=1;i<=n*m;i++){
		if(yk%2==1){
			xk++;
			if(xk>n){
				xk=n;
				yk++;
			}
		}
		else{
			xk--;
			if(xk<=0){
				xk=1;
				yk++;
			}
		}
		if(a[i].bh==1){
			cout<<yk<<" "<<xk;
			return 0;
		}
	}
	return 0;
}
