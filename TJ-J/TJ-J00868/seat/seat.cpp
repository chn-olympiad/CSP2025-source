#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int u,int v){
	return u>v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int fir=a[1];
	sort(a+1,a+1+t,cmp);
	int x=1,y=1;
	for(int i=1;i<=t;i++){
		if(a[i]==fir){
			cout<<y<<' '<<x;
			break;
		}
		if( (y%2==1&&x==n)||(y%2==0&&x==1) ){
			y++;
		}else if(y%2==1){
			x++;
		}else{
			x--;
		}
	}
	return 0;
}
