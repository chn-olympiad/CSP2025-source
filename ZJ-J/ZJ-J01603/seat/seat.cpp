#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int t=n*m;
	for(int i=1;i<=t;i++) cin >> a[i];
	int q=a[1];
	sort(a+1,a+t+1,cmp);
	int w=0;
	for(int i=1;i<=t;i++){
		if(a[i]==q){
			w=i;
			break;
		}
	}
	int x=1,y=1,er=1;
	bool f=0;
	while(er!=w){
		if(f) y--;
		else y++;
		if(y>n){
			y=n;
			x++;
			f=!f;
		}
		if(y<1){
			y=1;
			x++;
			f=!f;
		}
		er++;
	}
	cout << x << " " << y;
	return 0;
}
