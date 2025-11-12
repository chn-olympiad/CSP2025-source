#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[110];
int id;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	id=1;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) id++;
	}
	int x=1,y=0;
	int t=1;
	while(id--){
		y+=t;
		if(y>n){
			y=n;
			x++;
			t=-1;
		}
		else if(y<1){
			y=1;
			x++;
			t=1;
		}
//		cout<<x<<" "<<y<<"\n";
	}
	cout<<x<<" "<<y;
	return 0;
}
