#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[100005],x=1,y=1,ans;
int main(){
	freopen(seat.in,"r",stdin);
	freopen(seat.out,"w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	ans=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==ans){
			break;
		}
		if(y%2==1){
			x++;
			if(x>n){
				y++;
				x--;
			}
		}else{
			x--;
			if(x==0){
				y++;
				x++;
			}
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
