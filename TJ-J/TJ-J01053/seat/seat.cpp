#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std ;
bool cmp(int x,int y){
return x>y ;
}
int n,m,z,temp,id=1,h=1 ;
int d=0 ;
int x[2]={1,-1} ;
int a[20][20] ;
int ch[1010] ;
int main(){
freopen("seat.in","r",stdin) ;
freopen("seat.out","w",stdout) ;
cin >> n >> m ;
z=n*m ;
for(int i=1;i<=z;i++){
cin >> ch[i] ;
}
temp=ch[1] ;
sort(ch+1,ch+z+1,cmp) ;//score≈≈–Ú 
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
	a[h][i]=ch[id] ;
	id++ ;
	h=h+x[d] ;
	}
d=(d+1)%2 ;
h=h+x[d] ;
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
	  if(a[i][j]==temp){
	  cout << j << " " << i ;
      }
	}
}
return 0 ;
}
