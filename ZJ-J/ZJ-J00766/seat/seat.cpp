#include<bits/stdc++.h>
using namespace std;
int n,m;
struct jj{
	bool f;
	int g;
}a[209];
bool cmp(jj x,jj y){
	return x.g>y.g;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i].g;
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1;
	for(int i=1;i<=n*m;i++){
		if(y%2==1){
			x++;
			if(x>n){
				x=n;
				y++;
			}
		}
		else if(y%2==0){
			x--;
			if(x==0){
				x=1;
				y++;
			}
		}
		if(a[i].f==1){
			cout<<y<<" "<<x;
			return 0;
		}
	}
}
