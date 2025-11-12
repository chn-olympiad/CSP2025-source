#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int c/*xiaoR's score*/=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x/*lie*/=1,y/*hang*/=1/*weizhi*/;
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			cout<<x<<" "<<y;
			break;
		}
		if(x%2==1) y++;
		else y--;
		if(y>n){
			x++;
			y=n;
		}
		if(y<1){
			x++;
			y=1;
		}
	}
	return 0;
}
