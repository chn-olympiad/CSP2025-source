#include <iostream>
using namespace std;
int n,m,c,r;//n行m列，第c列第r行 
int N,R;	//N总人数，R小R成绩 
int p=1;	//p小R名次 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	N=n*m;
	cin>>R;
	for(int i=1;i<N;i++){
		int x;
		cin>>x;
		if(x>R){	//计算排名 
			p++;
		}
	}
	c=p/n;
	if(p%n){
		c++;
	}
	if(c%2){
		r=p%n;
		if(r==0){
			r+=n;
		}
	}else{
		r=n-(p-(n*(c-1)))+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
