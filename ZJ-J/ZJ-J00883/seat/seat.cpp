#include<bits/stdc++.h>
using namespace std;
bool a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
   int n,m,x,sum=1,b=0;
   cin>>n>>m;
   cin>>x;
   for(int i=2;i<=n*m;i++){
   	int y;
   	cin>>y;
   	 if(y>x){
   	 	sum++;
	 } 
   }
   if(sum%n==0) b=1;
   int l=sum/n-b+1;
   if(sum%n==0){
   	 if(l%2==0) cout<<l<<" "<<1;
   	 else cout<<l<<" "<<n;
   }
   else{
   	 if(l%2==0) cout<<l<<" "<<n-sum%n+1;
   	 else cout<<l<<" "<<sum%n;
   }
	return 0;
}
