#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[101],r,r_d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<(n*m);i++){
		cin>>a[i];
	}
	r = a[0];
	sort(a,a+(n*m),cmp);
	for(int i=0;i<(n*m);i++){
		if(a[i]==r) r_d=i+1;
	}
	int x,yt=r_d%n,y;
	if(yt==0) x=r_d/n;
	else x=r_d/n+1;
	if(x%2==0){
	 	if(yt==0){
	 		y=1;
		}
		else y=n-yt+1;
	}
	else {
		if(yt==0){
	 		y=n;
		}
		else y=yt;
	}
	cout<<x<<" "<<y;
	return 0;
}
