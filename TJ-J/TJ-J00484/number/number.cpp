#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin); 
freopen("number.out","w",stdout);
    int s,a,b,c,d;
    
  	cin>>s;
	  if(s<=10){
	  cout<<s;
	  return 0;
}
  	if(s<100){
  	a=s/10;
    b=s-a*10;
  	if(a<b){
  	cout<<b<<a;
  	return 0;
  }
  	else{
  	cout<<a<<b;
  	return 0;
  }
  }
  	if(s<1000){
  	a=s/100;
    b=s-a*100;
    c=b/10;
    b=b-c*10;

    cout<<a<<b<<c<<endl;
    cout<<b<<a<<c<<endl;
    cout<<c<<b<<a<<endl;
    cout<<c<<a<<b<<endl;
    cout<<a<<c<<b<<endl;
    cout<<b<<c<<a<<endl;
}

fclose(stdin);
fclose(stdout);
return 0; 

}
