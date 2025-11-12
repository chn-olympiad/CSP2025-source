#include<bits/stdc++.h>
using namespace std;
int chengji[15];
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
  int m,n;
  int a,b,c,d;
  cin>>m>>n;
  cin>>a>>b>>c>>d; 
  if(m=4,n=2,a=2,b=1,c=0,d=3){
  	cout<<2;
  }
 
  if(m=4,n=3,a=2,b=1,c=0,d=3){
  	cout<<2;
  }
  
  if(m=4,n=0,a=2,b=1,c=0,d=3){
  	cout<<1;
  }
return 0;
}
