#include<bits/stdc++.h>
using namespace std;
const int N=1e3+17;
int a[N],me;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	me=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x,y;
	x=y=1;
	int op=1;
	for(int i=1;i<=n*m;i++){
		
		if(a[i]==me){
			cout<<y<<" "<<x;
			return 0;
		}
		if((x==n&&y%2==1)||(x==1&&y%2==0)){
			y++;
			op=-op;
		}
		else
			x+=op;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/