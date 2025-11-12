#include<bits/stdc++.h>
using namespace std;
int n,m,r,num,a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>r){
			num++;
		}
	}
	if((num/n)%2==0) cout<<num/n+1<<' '<<num%n+1;
	else cout<<num/n+1<<' '<<n-num%n;
	return 0;
}
