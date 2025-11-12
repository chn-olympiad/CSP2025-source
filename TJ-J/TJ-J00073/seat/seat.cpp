#include<iostream>
#include<cstdio>
using namespace std;
short n,m,seat=1,fen,myfen;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>myfen;
	for(short i=1;i<n*m;i++){
        cin>>fen;
        if(fen>myfen) seat++;
	}
	if(seat%n){
        cout<<seat/n+1<<' ';
        if((seat/n+1)%2){
            cout<<seat%n;
        }else{
            cout<<n-seat%n+1;
        }
	}else{
        cout<<seat/n<<' ';
        if((seat/n)%2){
            cout<<n;
        }else{
            cout<<1;
        }
	}
	return 0;
}
