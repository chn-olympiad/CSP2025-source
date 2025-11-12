#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int r,a[110],l,nw,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	l=n*m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=l;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+l);
	for(int i=1;i<=l;i++){
		if(a[i]==r){
			nw=l-i+1;
		}
	}
	int x=(nw-1)/m+1,y=(nw-1)%m+1;
	cout<<x;
	if(x%2){
		cout<<' '<<y;
	}else{
		cout<<' '<<n-y+1;
	}
	return 0;
}

