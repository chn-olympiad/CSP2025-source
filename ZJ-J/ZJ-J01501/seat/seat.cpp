#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,a,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>a){
			cnt++;
		}
	}
	int fen=(cnt-1)/(n*2);
	int la=cnt-fen*(n*2);
	if(la>n){
		cout<<fen*2+2<<" "<<n*2-la+1;
	}
	else{
		cout<<fen*2+1<<" "<<la;
	}
	return 0;
}