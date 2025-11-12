#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int b[m*n],c,e[1];
for(int i=0;i<=m*n;i++){
	cin>>b[i];
} 
for(int i=1;i<=m*n;i++){
	if(b[0]>b[i]){
		c++;
	}	
}
for(int i=1;1<=n;n++){
if(c>=m){
	cout<<i<<c;
	board;//
}else((c-i*m)>=m){
	cout<<i<<c-i*m; 
}
}

	return 0;
}
