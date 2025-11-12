#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int n;
   cin>>n;
    if(n%1000>n%10&&n%1000>n%100&&n%100>n%10){
    cout<<n%100/10<<n%1000/100<<n%10+100;	
  	}else{
		cout<<n;

	}
    return 0;
}
