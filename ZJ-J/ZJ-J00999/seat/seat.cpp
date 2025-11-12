#include <bits/stdc++.h>
using namespace std;
//1<=n,m<=10
//1<=a_i<=100
//a_1,a_2...a_n*m hu bu xiang tong
struct wky{
	int x,h;
	bool operator < (const wky&ot)const{
		return x>ot.x;
	}
};
int n,m;
int t;
wky a[107];
int c=1,r=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i].x;
		a[i].h=i;
	}
	sort(a+1,a+1+t);
	for(int i=1;i<=t;i++){
		if(a[i].h==1){
			cout<<c<<' '<<r;
			return 0;
		}
		//yi dong c,r
		if(c%2==1){
			if(r+1<=n){
				++r;
			}
			else if(r+1>n){
				++c;
			}
		}
		else{
			if(r-1>=1){
				--r;
			}
			else if(r-1<1){
				++c;
			}
		}
//		cerr<<"c: "<<c<<"  r: "<<r<<'\n';
	}
	return 0;
}
