#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int n,m;
int a[N];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	int cnt=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			id=i;
			break;
		}
	}
	int h=0,l=0;
	if(id%n!=0) l=id/n+1;
	else l=id/n;
	if(l%2==1){
		for(int i=0;i<=n;i++){
			if(id==l*n-i){
				h=n-i;
				break;
			}
		}
	}
	else{
		for(int i=0;i<=n;i++){
			if(id==l*n-i){
				h=i+1;
				break;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
