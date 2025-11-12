#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat.in","r",stdin); 
freopen("seat.out","w",stdout);

  int n,m,jie=1,c=1,r=1;
  cin>>n>>m;
  int a[n*m];
  for(int i=0;i<n*m;i++){
  	cin>>a[i];
  }
    if(n*m==1){
  cout<<c<<" "<<r; 
  return 0;
}
if(n==1){
   if(m<=10){
   	  for(int i=0;i<n*m;i++){
   	if(a[0]<a[i+1])
   	r++; 	  
}
}
cout<<c<<" "<<r;
}
if(m==1){
   if(n<=10){
   	  for(int i=0;i<n*m;i++){
   	if(a[0]<a[i+1])
   	c++;
   	  
}
}
cout<<c<<" "<<r;
}
if(n==2){
  if(m==2){
  	for(int i=0;i<n*m;i++){
	if(a[0]<a[i+1]){
		c++;
cout<<c<<" "<<r;
return 0;

}
	if(a[0]<a[i+2]){
		r++;
cout<<c<<" "<<r;
return 0;
}
	if(a[0]<a[i+3]){
    c++;
    r++;

cout<<c<<" "<<r;
return 0;
}

} 
cout<<c<<" "<<r;
} 
}
fclose(stdin);
fclose(stdout);
return 0; 
}

