#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m,k,p,t,x,y;
	cin>>n>>m;
	k = n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	p = a[1];
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--){
		if(a[i]==p){
			t = k-i+1;
			break;
		}
	}
	x = (t-1)/n+1;
	y = (t-1)%n+1;
	if(x%2==0){
		y = n-y+1;
	}
	cout<<x<<' '<<y;
	return 0;
}
