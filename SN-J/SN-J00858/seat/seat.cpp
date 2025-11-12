// SN-J00858
// TYZ
// csy
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,m,x,y,s;
void sol(){
	cin>>n>>m>>s;
	x=y=1;
	for(int i=1,c;i<n*m;i++){
		cin>>c;
		if(c>s){
			if(x&1){
				y++;
				if(y>n) y=n,x++;
			}else{
				y--;
				if(y<1) y=1,x++;
			}
		}
	}
	cout<<x<<' '<<y<<endl;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	ii();
//	int TT;for(cin>>TT;TT--;)
	sol();
	return 0;
}
