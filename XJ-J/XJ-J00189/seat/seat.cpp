#include<bits/stdc++.h>
using namespace std;
int a[110];
int s[20][20];
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,x,xi;
  cin>>n>>m;
  for(int i=1;i<=n*m;i++){
  	cin>>a[i];
  }
  x=a[1];
  for(int i=1;i<=n*m;i++){
  	for(int j=i+1;j<=n*m;j++){
  	  if(a[j]>a[i]){
  	  	swap(a[i],a[j]);
	  }
	} 
  }
  for(int i=1;i<=n*m;i++){
  	if(a[i]==x){
  	  xi=i;
  	  break;
	}
  }
  for(int j=1;j<=m;j+=2){
  	for(int i=1;i<=n;i++){
  	  int k;
  	  s[i][j]=(j-1)*n+1+(i-1);
	}
  }
  for(int j=2;j<=m;j+=2){
  	for(int i=1;i<=n;i++){
  	  int k;
  	  s[i][j]=j*n-(i-1);
	}
  }
  for(int i=1;i<=n;i++){
  	for(int j=1;j<=m;j++){
  	  if(s[i][j]==xi){
  	  	cout<<j<<" "<<i;
  	  	return 0;
	  }
	}
  }
return 0;
}
