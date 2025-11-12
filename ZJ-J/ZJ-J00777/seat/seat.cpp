#include<bits/stdc++.h>
const int slen=1e4+10;
using namespace std;
int a[slen];
bool cmp(int a,int b){
  return a>b;
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,res;
  cin>>n>>m;
  for(int i=1;i<=n*m;i++)cin>>a[i];
  res=a[1];
  sort(a+1,a+n*m+1,cmp);
  int j=1;
  for(int i=1;i<=m;i++){
  	if(i%2==1){
  	  while(j<=n){
  	    if(a[(i-1)*n+j]==res){
  	      cout<<i<<' '<<j;
  	      return 0;
		}
	    j++;
	  }
	}
    if(i%2==0){
  	  while(j>=1){
  	    if(a[i*n-j+1]==res){
  	      cout<<i<<' '<<j;
  	      return 0;
		}
		j--;
	  }
	}
  }
  return 0;
}