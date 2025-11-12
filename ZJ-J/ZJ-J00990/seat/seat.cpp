#include<bits/stdc++.h>
using namespace std;
int const N=15;
int val[N*N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>val[i];
	int val_r=val[1];
	sort(val+1,val+n*m+1,cmp); // less
	int x=1,y=1; // x->lie y->hang
	int now=1; // id
	int d=1; // dirction
	do{
		if(val[now]==val_r){
			cout<<x<<' '<<y;
			return 0;
		}
		y+=d;
		now++;
		if(y==0){ // up to top
			y=1;
			x++;
			d=1;
		}
		else if(y==m+1){ // down to floor
			y=m;
			x++;
			d=-1;
		}
	}while(1);
	return 0;
}