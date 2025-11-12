#include<bits/stdc++.h>
using namespace std;
int a[1050];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)q=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	if(a[1]==q){
		cout<<1<<" "<<1;
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(x%2==1)y++;
		else y--;
		if(y>n){
			y--;
			x++;
		}
		if(y<1){
			y++;
			x++;
		}
		if(a[i]==q){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}

