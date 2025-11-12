#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int a[114];
for(int i=1;i<=n*m;i++){
	cin>>a[i];
}
int q=a[1];
sort(a+1,a+n*m+1);
int b,c,j; 
for(int i=1;i<=n*m;i++){
	if(q==a[i]){
		j=i;
		break;
	}
}
b=j/3;
if(j%n!=0){
	b++;
}
c=j%n;
if(c==0){
	c=n;
}
cout<<c<<" "<<b;
return 0;


}
