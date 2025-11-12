#include<bits/stdc++.h>
using namespace std;
const int N=13;
int a[N][N];
int cj[105];
bool cmp(int a,int b){
	return a>b;
}
int cnt=1;
int main(){
   freopen("seat.in","r",stdin); 
   freopen("seat.out","w",stdout); 
   int n,m;
   cin >> n >> m;
   for(int i=1;i<=n*m;i++){
   	cin >> cj[i];
   }
   int R=cj[1];
   sort(cj+1,cj+n*m+1,cmp);
   if(R==cj[1]){
   	cout << 1 <<" "<< 1;
   	return 0;
   }
   for(int i=1;i<=m;i++){
   	  if(i%2!=0){
   	  	for(int j=1;j<=n;j++){
   	  		a[i][j]=cj[cnt];
   	  		if(a[i][j]==R){
   	  			cout << i <<" "<< j;
   	  			return 0;
			}
   	  		cnt++;
		}
	  }else{
	  	for(int j=n;j>=1;j--){
	  		a[i][j]=cj[cnt];
	  		if(a[i][j]==R){
   	  			cout << i <<" "<< j;
   	  			return 0;
			}
   	  		cnt++;
		  }
	  }
   }
   return 0;
}
