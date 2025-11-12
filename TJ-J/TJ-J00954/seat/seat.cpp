#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	int cnt=0;
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		if(b>a){
			cnt++;
		}
	}
	cnt++;
	int lie=cnt/n;
	int hang=cnt%n;
	if(cnt%n==0){
		if(lie%2!=0){
			cout<<lie<<' '<<n;
		}else{
			cout<<lie<<' '<<1;
		}
	}else{
		if((lie+1)%2!=0){
			cout<<lie+1<<' '<<hang;
		}else{
			cout<<lie+1<<' '<<n-hang+1;
		}
	}
	
	return 0;
}
