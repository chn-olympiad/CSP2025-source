#include<bits/stdc++.h>
using namespace std;
long long n,m,a,x,y,s=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			if(x>a)s++;
		}
	}
	x=(s+n-1)/n;
	y=s-(x-1)*n;
	cout<<x<<' ';
	if(x%2==0){
		cout<<n-y+1;
	}else{
		cout<<y;
	}
	return 0;
}